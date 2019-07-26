#include <string>
#include <vector>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int smaller, bigger;
    
    if(a < b)
    {
        smaller = a;
        bigger = b;
    }
    else
    {
        smaller = b;
        bigger = a;
    }
    
    for(int i = smaller; i <= bigger; i++)
        answer += i;
    
    return answer;
}