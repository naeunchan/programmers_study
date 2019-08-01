#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    const char * tmp = s.c_str();
    int cnt = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(tmp[i] == ' ')
        {
            cnt = 0;
            answer.push_back(' ');
        }
        else
        {
            if(cnt % 2 == 0)
            {
                if(tmp[i] >= 97 && tmp[i] <= 122)
                    answer.push_back(tmp[i] - 32);
                else
                    answer.push_back(tmp[i]);
            }
            else
            {
                if(tmp[i] >= 65 && tmp[i] <= 90)
                    answer.push_back(tmp[i] + 32);
                else
                    answer.push_back(tmp[i]);
            }
            cnt++;
        }
    }
    return answer;
}