#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    bool check;
    
    for(int i = 123; i <= 987; i++)
    {
        string num = to_string(i);
        check = true;
        
        if(num[0] == num[1] || num[1] == num[2] || num[2] == num[0] || num[0] == '0' || num[1] == '0' || num[2] == '0')
            continue;
        
        for(int j = 0; j < baseball.size(); j++)
        {
            int strike = 0;
            int ball = 0;
            
            for(int k = 0; k < 3; k++)
            {
                for(int l = 0; l < 3; l++)
                {
                    string tmp = to_string(baseball[j][0]);
                    
                    if(k == l && num[k] == tmp[l])
                        strike++;
                    else if(k != l && num[k] == tmp[l])
                        ball++;
                }
            }
            
            if(strike != baseball[j][1] || ball != baseball[j][2])
            {
                check = false;
                break;
            }
        }
        
        if(check)
            answer++;
    }
    
    return answer;
}