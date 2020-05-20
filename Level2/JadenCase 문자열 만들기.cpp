#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            answer += ' ';
            index = 0;
        }
        else
        {
            if(index == 0)
                answer += toupper(s[i]);
            else
                answer += tolower(s[i]);
            index++;
        }
    }
    return answer;
}