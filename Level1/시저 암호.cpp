#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    const char * tmp = s.c_str();
    for(int i = 0; i < s.size(); i++)
    {
        if(tmp[i] != ' ')
        {
            if(tmp[i] >= 65 && tmp[i] <= 90)
                answer.push_back((tmp[i] - 'A' + n)% 26 + 'A');
            else if(tmp[i] >= 90 && tmp[i] <= 122)
                answer.push_back((tmp[i] - 'a' + n)%26 + 'a');
        }
        else
            answer.push_back(' ');
    }
    return answer;
}