#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool asc(vector<int> a,vector<int> b)
{
    if(a[1] == b[1])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int current = 0, size = jobs.size();
    sort(jobs.begin(), jobs.end(), asc);
    
    while(!jobs.empty())
    {
        for(int i = 0; i < jobs.size(); i++)
        {
            if(jobs[i][0] <= current)
            {
                current += jobs[i][1];
                answer += current - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }
            if(i == jobs.size() - 1)
                current++;
        }
    }
    return answer / size;
}