#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> arr;
    int tmp, min, max;
    
    for(int i = 0; i < operations.size(); i++)
    {
        if(operations[i][0] == 'I')
        {
            tmp = stoi(operations[i].substr(2));
            arr.push_back(tmp);   
        }
        else
        {
            if(!arr.empty())
            {
                if(operations[i][2] == '-')
                {
                    //min delete
                    min = *min_element(arr.begin(), arr.end());
                    arr.erase(find(arr.begin(), arr.end(), min));
                }
                else
                {
                    //max delete
                    max = *max_element(arr.begin(), arr.end());
                    arr.erase(find(arr.begin(), arr.end(), max));
                }
            }
        }
    }
    
    if(arr.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*max_element(arr.begin(), arr.end()));
        answer.push_back(*min_element(arr.begin(), arr.end()));
    }
    return answer;
}