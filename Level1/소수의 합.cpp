#include <vector>

using namespace std;
bool prime[10000000] = {false,};

long long solution(int N) {
    long long answer = 0;
    
    for(int i = 2; i <= N; i++)
    {
       if(prime[i] == false)
           answer += i;
        for(int j = i + i; j <= N; j += i)
            prime[j] = true;
    }
    return answer;
}