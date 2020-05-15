#include <string>
#include <vector>
#include <stack>

using namespace std;

string recurse(string p);
string reverse(string u);
bool isRight(string u);

string solution(string p) {
    string answer = "";
    
    answer = recurse(p);
    return answer;
}

string recurse(string p)
{
    string answer = "", u, v;
    int o = 0, c = 0;
    
    if(p.empty())
        return answer;
    else
    {
        for(int i = 0; i < p.size(); i++)
        {
            if(p[i] == '(')
                o++;
            else
                c++;
            
            u.push_back(p[i]);
            
            if(o == c)
            {
                v = p.substr(i + 1);
                
                if(isRight(u))
                    answer += u;
                else
                {
                    answer.push_back('(');
                    answer += recurse(v);
                    v = p.substr(i + v.size() + 1);
                    answer.push_back(')');
                    answer += reverse(u);
                }
                p = v;
                o = c = 0;
                i = -1;
                u.clear();
                v.clear();
            }
        }
    }
    return answer;
}

bool isRight(string u)
{
    stack<char> s;
    
    if(u[0] == ')')
        return false;
    
    s.push('(');
    
    for(int i = 1; i < u.size(); i++)
    {
        if(u[i] == '(')
            s.push('(');
        else
        {
            if(!s.empty() || s.top() == '(')
                s.pop();
            else
                s.push(')');
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}

string reverse(string u)
{
    string answer = "";
    
    for(int i = 1; i < u.size() - 1; i++)
    {
        if(u[i] == '(')
            answer.push_back(')');
        else
            answer.push_back('(');
    }
    return answer;
}