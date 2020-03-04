#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 0, right = 0, mid = 0, before = 0;
    sort(times.begin(), times.end());
    
    right = (long long)times.back() * (long long)n;
    
    while(1)
    {
        long long tmp = 0;
        mid = (left + right) / 2;
        
        for(int i = 0; i < times.size(); i++)
            tmp += mid / (long long)times[i];
        
        if(before == mid)
            return mid + 1;
        else if(tmp < n)
            left = mid;
        else
            right = mid;
        before = mid;
    }
}