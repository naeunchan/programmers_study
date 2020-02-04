#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    
    if(s.front() == ')')
        return false;
    
    stk.push(s[0]);
    
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == '(')
            stk.push(s[i]);
        else if(s[i] == ')')
        {
            if(!stk.empty() && stk.top() == '(')
                stk.pop();
            else
                stk.push(s[i]);
        }
    }
    
    if(stk.empty())
        return true;
    else
        return false;
}