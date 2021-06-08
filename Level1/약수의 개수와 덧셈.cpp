#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int getCount(int n){
    int count = 0;
    
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            if(n / i == i){
                count++;
            }
            else{
                count += 2;
            }
        }
    }
    
    return count;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; i++){
        if(getCount(i) % 2){
            answer -= i;
        }
        else{
            answer += i;
        }
    }
    
    return answer;
}