#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int size = dungeons.size();
    vector<int> index(size, 0);
    
    for(int i = 1; i < size; i++){
        index[i] = i;
    }
    
    do{
        int newK = k;
        int result = 0;
        
        for(int i = 0; i < size; i++){
            if(newK >= dungeons[index[i]][0]){
                result++;
                newK -= dungeons[index[i]][1];
            }
        }
        
        answer = answer < result ? result : answer;
    }while(next_permutation(index.begin(), index.end()));
    
    return answer;
}