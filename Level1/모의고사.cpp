#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1[5] = {1,2,3,4,5};
    int p2[8] = {2,1,2,3,2,4,2,5};
    int p3[10] = {3,3,1,1,2,2,4,4,5,5,};
    int n1 = 0, n2 = 0, n3 = 0;
    int i1 = 0,i2 = 0,i3 = 0;
    for(int i = 0; i < answers.size(); i++,i1++,i2++,i3++)
    {
        if(i1 % 5 == 0)
            i1 = 0;
        if(i2 % 8 == 0)
            i2 = 0;
        if(i3 % 10 == 0)
            i3 = 0;
        if(p1[i1] == answers.at(i))
            n1++;
        if(p2[i2] == answers.at(i))
            n2++;
        if(p3[i3] == answers.at(i))
            n3++;
    }
    
    if(n1 == n2 && n2 == n3 && n1 == n3)
    {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    else if(n1 > n2 && n1 > n3)
        answer.push_back(1);
    else if(n2 > n1 && n2 > n3)
        answer.push_back(2);
    else if(n3 > n1 && n3 > n2)
        answer.push_back(3);
    else if(n1 == n2 && n1 > n3)
    {
        answer.push_back(1);
        answer.push_back(2);
    }
    else if(n2 == n3 && n2 > n1)
    {
        answer.push_back(2);
        answer.push_back(3);
    }
    else if(n3 == n1 && n3 > n2)
    {
        answer.push_back(1);
        answer.push_back(3);
    }
    return answer;
}