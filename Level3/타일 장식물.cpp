#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long num[81] = {0, };
    
    num[1] = 1;
    num[2] = 1;
    
    for(int i = 3; i <= N; i++)
        num[i] = num[i - 1] + num[i - 2];
    
    answer = (4 * num[N]) + (2 * num[N - 1]);
    
    return answer;
}