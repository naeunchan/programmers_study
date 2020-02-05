#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1, tmp = 1, front = 1, end = 2;
    
    while(1)
    {
        if(tmp == n)
        {
            answer++;
            tmp -= (front++);
        }
        else if(tmp > n)
            tmp -= (front++);
        else
            tmp += (end++);
        if(end == n)
            break;
    }
    return answer;
}