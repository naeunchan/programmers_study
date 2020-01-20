#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int gcd(int a, int b);
int lcm(int a, int b);

int solution(vector<int> arr) {
    int answer = 0;
    
    //오름차순 정렬
    sort(arr.begin(), arr.end());
    answer = arr[0];
    
    for(int i = 1; i < arr.size(); i++)
    {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}

int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}