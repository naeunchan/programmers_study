#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    
    if(n == 1)
        return answer;
    
    for(int i = 2; i <= n; i++)
    {
        vector<int> tmp = answer;
        answer.push_back(0);
        
        for(int j = tmp.size() - 1; j >= 0; j--)
        {
            if(tmp[j] == 0)
                answer.push_back(1);
            else
                answer.push_back(0);
        }
    }
    return answer;
}