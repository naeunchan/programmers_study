#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0, max = nums.size() / 2;
    bool check[200001] = {false, };
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(answer == max)
            return answer;
        if(check[nums[i]] == false)
        {
            check[nums[i]] = true;
            answer++;
        }
    }
}