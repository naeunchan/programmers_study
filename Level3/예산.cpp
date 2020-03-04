#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int min, max, mid, before = 0;
    long long sum = 0; 
    
    sort(budgets.begin(), budgets.end());    
    min = 1;
    max = 100000;
    
    for(int i = 0; i < budgets.size(); i++)
        sum += (long long)budgets[i];
    
    if(sum <= (long long)M)
        return budgets.back();
    
    while(1)
    {
        sum = 0;
        mid = (min + max) / 2;
        
        for(int i = 0; i < budgets.size(); i++)
        {
            if(budgets[i] < mid)
                sum += (long long)budgets[i];
            else
            {
                sum += (long long)(mid * (budgets.size() - 1 - (i - 1)));
                break;
            }
        }
        if(before == mid)
            return mid;
        else if(sum > M)
            max = mid;
        else
            min = mid;
        before = mid;
    }
}