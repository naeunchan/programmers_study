#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0, maxV;
    
    for(int i = 1; i < land.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            maxV = 0;
            for(int k = 0; k < 4; k++)
            {
                if(j != k)
                    maxV = max(maxV, land[i - 1][k]);
            }
            land[i][j] += maxV;
        }
    }
    for(int i = 0; i < 4; i++)
        answer = max(answer, land[land.size() - 1][i]);
    return answer;
}