#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int i, j, sec;
    
    for(i = 0; i < prices.size() - 1; i++)
    {
        sec = 0;
        for(j = i + 1; j < prices.size(); j++)
        {
            if(prices.at(i) <= prices.at(j))
                sec++;
            else
            {
                sec++;
                break;
            }
        }
        answer.push_back(sec);
    }
    answer.push_back(0);
    return answer;
}