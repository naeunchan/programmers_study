#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    for(int i = 0; i < heights.size(); i++)
    {
        if(i == 0)
            answer.push_back(0);
        else
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(heights.at(i) < heights.at(j))
                {
                    answer.push_back(j+1);
                    break;
                }
                if(j == 0 && heights.at(i) >= heights.at(j))
                    answer.push_back(0);
            }
        }
    }
    return answer;
}