#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int sum = brown + red;
    int a = 0, b = 0;
    int index = sum;
    bool check[sum + 1];
    
    for(int i = 2; i <= sum; i++)
    {
        check[i] = false;
        if(sum % i == 0)
            check[i] = true;
    }
    
    while(1)
    {
        if(index < brown && check[index] == true)
        {
            a = index;
            b = sum / index;
            if(2 * a + (b - 2) * 2 == brown)
            {
                answer.push_back(a);
                answer.push_back(b);
                return answer;
            }
        }
        index--;
    }
    return answer;
}