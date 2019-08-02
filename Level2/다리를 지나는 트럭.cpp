#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current = 0;
    int save = 0;
    queue<int> going;
    
    for(int i = 0; i < bridge_length; i++)
        going.push(0);

    while(!going.empty())
    {
        answer++;
        going.pop();
        current -= save;
        if(!truck_weights.empty())
        {
            if(current + truck_weights.front() <= weight)
            {
                current += truck_weights.front();
                going.push(truck_weights.front());
                truck_weights.erase(truck_weights.begin());
            }
            else
                going.push(0);
        }
        save = going.front();
    }
    return answer;
}