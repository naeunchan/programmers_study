#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> wait;
    for(int i = 0; i < priorities.size(); i++)
        wait.push(priorities[i]);
    
    sort(priorities.begin(),priorities.end());    

    while(1)
    {
        if(wait.front() != priorities.back())
        {
            wait.push(wait.front());
            wait.pop();
            location--;
            if(location < 0)
                location = wait.size() - 1;
        }
        else
        {
            if(location == 0)
                return ++answer;
            else
            {
                answer++;
                wait.pop();
                priorities.pop_back();
                location--;
            }
        }
    }    
}