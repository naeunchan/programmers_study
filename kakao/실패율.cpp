#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> fail;
    vector<double> s;
    
    for(int i = 1; i <= N; i++)
    {
        double p = 0; //스테이지에 도달한 플레이어 수
        double np = 0; //스테이지에 도달했으나 클리어하지 못한 플레이어 수
            
        for(int j = 0; j < stages.size(); j++)
        {    
            if(stages[j] > i)
                p++;
            else if(stages[j] == i)
                np++;
        }
        if(p == 0 && np == 0)
            fail.push_back(0);
        else if(p == 0 && np != 0)
            fail.push_back(100);
        else
            fail.push_back(np/p);
    }
    s = fail;
    sort(s.begin(), s.end(), greater<double>());

    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0; j < fail.size(); j++)
        {
            if(s[i] == fail[j])
            {
                answer.push_back(j + 1);
                fail[j] = -1;
            }
        }
    }
    return answer;
}