#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[2001];

long long solution(int n) {
    long long answer = 0;    
    arr[0] = 1;
    arr[1] = 2;
    
    if(n > 1)
    {
        for(int i = 2; i <= n; i++)
            arr[i] = (arr[i - 2] + arr[i - 1])  % 1234567;
    }
    answer = arr[n - 1];   
    return answer;
}