#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    int current = 1, count = 0;
    string hex = "0123456789ABCDEF";
    string number = "0";
    
    while(count < t)
    {
        int tmp = current;
        int ind = p + m * count - 1;
        string rev = "";
        
        for(; tmp > 0;)
        {
            rev += hex[tmp % n];
            tmp /= n;
        }
        reverse(rev.begin(), rev.end());
        number += rev;
        
        if(ind < number.size())
        {
            answer += number[ind++];
            count++;
        }
        current++;
    }
    return answer;
}