#include <string>
#include <vector>

using namespace std;
bool visited[200] = {false, };

void dfs(int i, vector<vector<int>>& computers, int n)
{
    visited[i] = true;
    
    for(int j = 0; j < n; j++)
    {
        if(!visited[j] && computers[i][j])
            dfs(j, computers, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            answer++;
            dfs(i, computers, n);
        }
    }
    
    return answer;
}