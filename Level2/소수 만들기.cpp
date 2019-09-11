#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool arr[2998] = {false,};

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;
    
    
    sort(nums.begin(), nums.end());
    
    for(int i = 2; i <= 2997; i++)
        for(int j = i + i; j <= 2997; j += i)
            arr[j] = true;
    
    for(int i = 0; i < nums.size() - 2; i++)
    {
        for(int j = i + 1; j < nums.size() - 1; j++)
        {
            for(int k = j + 1; k < nums.size(); k++)
            {
                sum = nums[i] + nums[j] + nums[k];
                if(arr[sum] == false)
                    answer++;
            }
        }
    }

    return answer;
}