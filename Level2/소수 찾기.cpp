#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool prime[10000000] = {false,};

int solution(string numbers) {
    int answer = 0;
    int max = 0;
    int tmp = 0;
    sort(numbers.begin(), numbers.end(), greater<int>());
    max = atoi(numbers.c_str());
    
    for(int i = 2; i <= max; i++)
    {
        for(int j = i + i; j <= max; j += i)
            prime[j] = true;
    }
    sort(numbers.begin(), numbers.end()); 
    
    do
    {
        string str = "";
        tmp = 0;
        for(int j = 0; j < numbers.size(); j++)
        {
            str += numbers[j];
            tmp = atoi(str.c_str());
            if(tmp > 1 && prime[tmp] == false)
            {
                answer++;
                prime[tmp] = true;
            }
        }
        
    }while(next_permutation(numbers.begin(),numbers.end()));

    
    return answer;
}