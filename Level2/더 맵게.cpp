#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, tmp = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    
    while(pq.top() < K)
    {
        if(pq.size() == 1 && pq.top() < K)
            return -1;
        tmp = 0;
        tmp += pq.top();
        pq.pop();
        tmp += pq.top() * 2;
        pq.pop();
        pq.push(tmp);
        answer++;
    }
    return answer;
}