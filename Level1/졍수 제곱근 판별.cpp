#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long n) {
    long long answer = 0;
    long long tmp = sqrt(n);
    if(n == tmp * tmp)
        answer = pow(tmp+1,2);
    else
        answer = -1;
    return answer;
}