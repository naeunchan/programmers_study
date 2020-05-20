#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int current = brown + yellow;
    int sum = current;
    
    while(current > 1)
    {
        if(sum % current == 0)
        {
            int row = current;
            int col = sum / current;
            
            if(col > 1 && row >= col && row * 2 < brown)
            {
                int checkY = row * (col - 2) - (2 * (col - 2));
                
                if(checkY == yellow)
                {
                    answer.push_back(row);
                    answer.push_back(col);
                    return answer;
                }
            }
        }
        current--;
    }
    return answer;
}