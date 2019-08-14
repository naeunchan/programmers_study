#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int i = 0;
    priority_queue<int> pq;
    
    while(stock < k)
    {
        for(; i < dates.size(); i++)
        {
            if(dates[i] <= stock)
                pq.push(supplies[i]);
            else
                break;
            
        }
        answer++;
        stock += pq.top();
        pq.pop();
    }
    
    return answer;
}