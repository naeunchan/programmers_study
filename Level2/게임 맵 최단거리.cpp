#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 1;
    int n = maps.size();
    int m = maps[0].size();
    int goalX = n - 1, goalY = m - 1;
    int directX[4] = {-1, 1, 0, 0};
    int directY[4] = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i = 0; i < size; i++){
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
                        
            for(int j = 0; j < 4; j++){
                int nextX = x + directX[j];
                int nextY = y + directY[j];
                
                if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && maps[nextX][nextY] != 0 && !visited[nextX][nextY]){
                    if(nextX == goalX && nextY == goalY){
                        return answer + 1;
                    }
                    q.push(make_pair(nextX, nextY));
                    visited[nextX][nextY] = true;
                }
            }
        }
        answer++;
    }
    
    return -1;
}