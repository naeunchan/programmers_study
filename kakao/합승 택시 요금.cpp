#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    vector<vector<int>> fare(201, vector<int>(201, 99999999));
    
    for(int i = 1; i <= n; i++){
        fare[i][i] = 0;
    }
    
    for(int i = 0; i < fares.size(); i++){
        int c = fares[i][0];
        int d = fares[i][1];
        int f = fares[i][2];
        
        fare[c][d] = f;
        fare[d][c] = f;
    }
    
    //플로이드 와샬
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                fare[j][k] = min(fare[j][k], fare[j][i] + fare[i][k]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        answer = min(answer, fare[s][i] + fare[i][a] + fare[i][b]);
    }
    
    return answer;
}