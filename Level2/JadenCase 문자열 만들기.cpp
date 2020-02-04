#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        if(i == 0)
        {
            if(s[i] >= '0' && s[i] <= '9')
                answer += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z')
                answer += s[i];
            else
                answer += toupper(s[i]);
        }
        else if(s[i - 1] == ' ')
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                answer += s[i];
            else
                answer += toupper(s[i]);
        }
        else
        {
            if(s[i] >= 'A' && 'Z')
                answer += tolower(s[i]);
            else
                answer += s[i];
        }
    }
    return answer;
}