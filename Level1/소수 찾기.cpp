#include <string>
#include <vector>
bool prime[1000001] = {false,};
using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 2; i <= n; i++)
    {
        if(prime[i] == false)
           answer++;
        for(int j = i + i; j <= n; j += i)
            prime[j] = true;
    }
    return answer;
}