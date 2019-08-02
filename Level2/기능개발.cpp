#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> remain;
    int cnt, front, tmp;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        tmp = (100 - progresses[i]) / speeds[i];
        if(tmp * speeds[i] + progresses[i] < 100)
            tmp += 1;
        remain.push_back(tmp); 
    }
    
    while(!remain.empty())
    {
        cnt = 0;
        front = remain.front();
        for(auto it = remain.begin(); it != remain.end(); it++)
        {
            if(front >= *it)
                cnt++;
            else
                break;
        }
        for(int i = 0; i < cnt; i++)
            remain.erase(remain.begin());
        answer.push_back(cnt);
    }
    return answer;
}