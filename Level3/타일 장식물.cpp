#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long arr[80] = {0, };
    
    arr[1] = 1;
    arr[2] = 1;
    
    for(int i = 3; i <= N; i++)
        arr[i] = arr[i - 1] + arr[i - 2];
    
    answer = (arr[N] * 4) + (arr[N - 1] * 2);
    return answer;
}