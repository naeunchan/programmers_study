#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int>::iterator it;
    
    for(int i = reserve.size() - 1; i >= 0; i--)
    {
        if((it = find(lost.begin(),lost.end(), reserve.at(i))) != lost.end())
        {
            answer++;
            lost.erase(it);
            reserve.erase(find(reserve.begin(), reserve.end(), reserve.at(i)));
        }
    }
    
    while(!lost.empty() && !reserve.empty())
    {
        if((it = find(reserve.begin(),reserve.end(),lost.front() - 1)) != reserve.end() ||
                (it = find(reserve.begin(),reserve.end(),lost.front() + 1)) != reserve.end())
        {
            answer++;
            reserve.erase(it);
        }
        lost.erase(lost.begin());
    }
    return answer;
}