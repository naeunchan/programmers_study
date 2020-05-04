#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> arr = triangle;
    
    arr[0][0] = triangle[0][0];
    
    for(int i = 1; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
            arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + triangle[i][j];
    }
    
    answer = *max_element(arr[arr.size() - 1].begin(), arr[arr.size() - 1].end());
    return answer;
}