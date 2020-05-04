#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int pre = arr[0];
    answer.push_back(pre);
    
    for(int i = 1; i < arr.size(); i++)
    {
        if(pre != arr[i])
        {
            pre = arr[i];
            answer.push_back(pre);
        }
    }
    
    return answer;
}