#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool desc(int a, int b)
{
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 1;
    vector<int> tmp = priorities;
    
    sort(tmp.begin(), tmp.end(), desc);
    
    while(1)
    {
        if(tmp.front() != priorities.front())
        {
            if(location == 0)
                location = priorities.size() - 1;
            else
                location--;
            priorities.push_back(priorities.front());
            priorities.erase(priorities.begin());
        }
        else
        {
            if(location == 0)
                return answer;
            else
            {
                answer++;
                tmp.erase(tmp.begin());
                priorities.erase(priorities.begin());
                location--;
            }
        }
    }
    return answer;
}