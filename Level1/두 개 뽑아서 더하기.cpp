#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    bool check[200] = {false, };
    
    for(int i = 0; i < numbers.size(); i++)
    {
        for(int j = i + 1; j < numbers.size(); j++)
        {
            int sum = numbers[i] + numbers[j];
            
            if(check[sum] == false)
            {
                answer.push_back(sum);
                check[sum] = true;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}