#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    answer.push_back(arr.front());
    for(int i = 0; i < arr.size(); i++)
    {
        if(find(answer.end() - 1, answer.end(), arr.at(i)) == answer.end())
            answer.push_back(arr.at(i));
    }
    return answer;
}