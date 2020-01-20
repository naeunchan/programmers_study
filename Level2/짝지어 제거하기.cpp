#include <iostream>
#include <stack>
#include <string>
using namespace std;

int solution(string s)
{
    int answer = 0, j = 0;
    stack<char> word;
    char pre;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(word.empty() || word.top() != s[i])        
            word.push(s[i]);
        else
            word.pop();
    }
    
    if(word.empty())
        answer = 1;
    return answer;
}