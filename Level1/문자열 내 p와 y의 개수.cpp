#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int numP = 0, numY = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s.at(i) == 'p' || s.at(i) == 'P')
            numP++;
        else if(s.at(i) == 'y' || s.at(i) == 'Y')
            numY++;
    }
    if(numP == numY)
        answer = true;
    else
        answer = false;

    return answer;
}