#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

int answer = 9999;

void bfs(vector<vector<bool>> graph, int n, int currentNode){
    vector<bool> visited(n + 1, false);
    queue<int> q;
    int cnt = 0;
    
    q.push(currentNode);
    visited[currentNode] = true;
    
    while(!q.empty()){
        int node = q.front();
        
        q.pop();
        
        cnt++;
        
        for(int i = 1; i <= n; i++){
            if(!visited[i] && graph[node][i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    
    answer = answer > abs(cnt - (n - cnt)) ? abs(cnt - (n - cnt)) : answer;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    
    for(int i = 0; i < wires.size(); i++){
        int start = wires[i][0];
        int end = wires[i][1];
        
        graph[start][end] = true;
        graph[end][start] = true;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!visited[i][j] && graph[i][j]){
                visited[i][j] = true;
                visited[j][i] = true;
                
                graph[i][j] = false;
                bfs(graph, n, i);
                graph[i][j] = true;   
            }
        }
    }
    
    return answer;
}