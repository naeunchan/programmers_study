#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

#define PAIR pair<pair<double, int>, pair<int, int>>

using namespace std;

bool desc(PAIR a, PAIR b){
    if(a.first.first == b.first.first){
        if(a.first.second == b.first.second){
            if(a.second.first == b.second.first){
                return a.second.second < b.second.second;
            }
            
            return a.second.first > b.second.first;
        } 
        
        return a.first.second > b.first.second;
    }
    
    return a.first.first > b.first.first;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<PAIR> rating;
    set<int> weightsSet;
    map<int, int> weightsMap;
    int size = weights.size();
    int rank = 0;
        
    for(int i = 0; i < size; i++){
        weightsSet.insert(weights[i]);
    }
    
    for(auto itr = weightsSet.begin(); itr != weightsSet.end(); itr++){
        weightsMap[*itr] = rank++;
    }
    
    for(int i = 0; i < size; i++){
        double total = size;
        double win = 0;
        int heavier = 0;
        int index = weightsMap[weights[i]];
        double rate = 0;
        
        for(int j = 0; j < size; j++){
            if(head2head[i][j] == 'W'){
                if(weights[i] < weights[j]){
                    heavier++;
                }
                win++;
            } else if(head2head[i][j] == 'N'){
                total--;
            }
        }
        
        if(total == 0){
            rate = 0;
        }else{
            rate = win / total;
        }
        rating.push_back({{rate, heavier}, {index, i}});
    }
    
    sort(rating.begin(), rating.end(), desc);
    
    for(auto itr = rating.begin(); itr != rating.end(); itr++){
        // cout << itr->first.first << " " << itr->first.second << " " << itr->second.first << " " << itr->second.second << endl;
        answer.push_back(itr->second.second + 1);
    }
    
    return answer;
}