#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int stick = 0;
    char before;
    
    for (int i = 0; i < arrangement.size(); i++)
    {
        if (arrangement[i] == '(')
            stick++;
        else
        {
            stick--;
            if (before == '(')
                answer += stick;
            else
                answer++;
        }
        before = arrangement[i];
    }
    return answer;
}