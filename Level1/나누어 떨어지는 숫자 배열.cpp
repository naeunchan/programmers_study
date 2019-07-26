#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    int size = arr.size();
    
    for(int i = 0; i < size; i++)
    {
        if(arr.at(i) % divisor == 0)
            answer.push_back(arr.at(i));
    }
    if(answer.empty())
        answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}