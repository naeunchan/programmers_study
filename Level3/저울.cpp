#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int answer = 1;
    sort(weight.begin(), weight.end());
    
    for(int i = 0; i < weight.size(); i++)
    {
        if(answer >= weight[i])
            answer += weight[i];
        else
            break;
    }
    return answer;
}