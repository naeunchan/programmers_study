#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
    int* answer = (int*)malloc(sizeof(int));
    int i = 0;
    while(n > 0)
    {
        answer[i] = n % 10;
        n /= 10;
        i++;
        answer = (int *)realloc(answer,sizeof(int)*(i+1));
    }
    return answer;
}