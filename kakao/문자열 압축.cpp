#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1000, cnt = 0, tmp = 0;
    string str;
    
    for(int i = 1; i <= s.size() / 2 + 1; i++)
    {
        cnt = 1;
        tmp = 0;
        str = s.substr(0, i);

        for(int j = i; j < s.size(); j += str.size())
        {
            if(str == s.substr(j, i))
                cnt++;
                
            else
            {
                if(cnt == 1)
                    tmp += str.size();
                else if(cnt < 10)
                    tmp += (str.size() + 1);
                else if(cnt < 100)
                    tmp += (str.size() + 2);
                else
                    tmp += (str.size() + 3);
                str = s.substr(j, i);
                cnt = 1;
            }
        }
        if(cnt == 1)
            tmp += str.size();
        else if(cnt < 10)
            tmp += (str.size() + 1);
        else if(cnt < 100)
            tmp += (str.size() + 2);
        else
            tmp += (str.size() + 3);
        if(tmp < answer)
            answer = tmp;
    }
    
    
    return answer;
}