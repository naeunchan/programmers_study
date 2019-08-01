#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int tmp;
    if(arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    else
        tmp = *min_element(arr.begin(),arr.end());
    
    arr.erase(find(arr.begin(),arr.end(),tmp));
    answer = arr;
    return answer;
}