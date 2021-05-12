#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(string s) {
    int answer = 0;
    queue<char> q;
    int size = s.size();
        
    for(int i = 0; i < size; i++){
        stack<char> stk;
        
        for(int j = 0; j < size; j++){
            if(s[j] == '[' || s[j] == '(' || s[j] == '{'){
                stk.push(s[j]);
            }
            else{
                if(!stk.empty()){
                    if((s[j] == ']' && stk.top() == '[') || (s[j] == ')' && stk.top() == '(') || (s[j] == '}' && stk.top() == '{')){
                        stk.pop();
                    }
                    else{
                        stk.push(s[j]);
                    }
                }
                else{
                    stk.push(s[j]);
                }
            }
        }
        
        if(stk.empty()){
            answer++;
        }
        s = s.substr(1) + s[0];
    }
    
    return answer;
}