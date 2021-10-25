#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    int n = enter.size();
    int leaveIndex = 0;
    vector<int> answer(n, 0);
    map<int, bool> m;
    
    for(int i = 0; i < n; i++){
        m[enter[i]] = true;
        
        for(int j = leaveIndex; j < n; j++){
            int num = leave[j];
            
            if(m[num]){
                int cnt = 0;
                
                m[num] = false;
                
                for(auto itr = m.begin(); itr != m.end(); itr++){
                    if(itr->second){
                        answer[itr->first - 1]++;
                        cnt++;
                    }
                }
                
                answer[num - 1] += cnt;
                leaveIndex++;
            } else{
                break;
            }
        }
    }
    
    return answer;
}