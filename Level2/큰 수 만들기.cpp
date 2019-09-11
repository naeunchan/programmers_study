#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size();
    int count = 0;
    int tmp = k;
    int flag = 0;
    k = size - k;
    
    while(1)
    {
        for(int j = 0; j < size; j++)
        {
            for(int m = 1; m <= tmp; m++)
            {    
                if(number[j] <number[j+m])
                    flag = 1;
                
                if (flag)
                    break;
            }
            
            if(flag)
            {
                tmp = tmp - 1;
                flag = 0;
            }
            else
            {
                answer += number[j];
                count++;
            }
            
            if(count >= k)
                return answer;
        }
    }
    
    return answer;
}