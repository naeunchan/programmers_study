#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int size = s.size();
    
    if(size % 2 == 1)
        answer.push_back(s.at(size / 2));
    else
    {
        for(int i = 1; i >= 0; i--)
            answer.push_back(s.at(size / 2 - i));
    }
    return answer;
}