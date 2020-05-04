#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool asc(vector<int> a, vector<int> b)
{
    return a[1] <= b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int spot = -30000;
    sort(routes.begin(), routes.end(), asc);
    
    for(int i = 0; i < routes.size(); i++)
    {
        if(spot < routes[i][0])
        {
            answer++;
            spot = routes[i][1];
        }
    }
    
    return answer;
}