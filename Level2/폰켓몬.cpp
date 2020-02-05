#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0, get = nums.size() / 2;
    bool arr[200001] = {false, };
    sort(nums.begin(), nums.end()); //오름차순 정렬
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(arr[nums[i]] == false)
        {
            arr[nums[i]] = true;
            answer++;
            if(answer > get)
                return answer - 1;
        }
    }
	return answer;
}