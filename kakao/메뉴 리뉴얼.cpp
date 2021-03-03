// #include <string>
// #include <vector>
// #include <map>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// vector<string> solution(vector<string> orders, vector<int> course) {
//     vector<string> answer;
//     map<string, int> m;
//     vector<int> count(11, 0);

//     for(int i = 0; i < orders.size(); i++){
//         int size = orders[i].size();
        
//         sort(orders[i].begin(), orders[i].end());
        
//         for(int j = 2; j <= size; j++){
//             vector<bool> index(size, false);
        
//             for(int k = size - j; k < size; k++){
//                 index[k] = true;
//             }
            
//             do{
//                 string s = "";
                
//                 for(int k = 0; k < index.size(); k++){
//                     if(index[k]){
//                         s += orders[i][k];
//                     }
//                 }
                
//                 m[s]++;
//                 count[s.size()] = count[s.size()] < m[s] ? m[s] : count[s.size()];
//             }while(next_permutation(index.begin(), index.end()));
//         }
//     }
    
//     for(int i = 0; i < course.size(); i++){
//         int c = course[i];
        
//         if(count[c] < 2){
//             continue;
//         }
//         for(auto itr = m.begin(); itr != m.end(); itr++){
//             if(itr->first.size() == c && itr->second == count[c]){
//                 answer.push_back(itr->first);
//             }
//         }
//     }
    
//     sort(answer.begin(), answer.end());
    
//     return answer;
// }

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> m;

    for(int i = 0; i < orders.size(); i++){
        int size = orders[i].size();
        
        sort(orders[i].begin(), orders[i].end());
        
        for(int j = 2; j <= size; j++){
            vector<bool> index(j, true);
        
            for(int k = 0; k < size - j; k++){
                index.push_back(false);
            }
            
            sort(index.begin(), index.end());
            
            do{
                string s = "";
                
                for(int k = 0; k < index.size(); k++){
                    if(index[k]){
                        s += orders[i][k];
                    }
                }
                
                m[s]++;
            }while(next_permutation(index.begin(), index.end()));
        }
    }
    
    for(int i = 0; i < course.size(); i++){
        int c = course[i], max = 0;
        vector<int> count;
        
        for(auto itr = m.begin(); itr != m.end(); itr++){
            if(itr->first.size() == c){
                count.push_back(itr->second);
            }
        }
        
        if(count.empty()){
            continue;
        }
        
        max = *max_element(count.begin(), count.end());
        
        for(auto itr = m.begin(); itr != m.end(); itr++){
            if(max >= 2 && itr->first.size() == c && itr->second == max){
                answer.push_back(itr->first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}