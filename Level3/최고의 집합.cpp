#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer(n, 0), tmp;
    int q = 0;
    
    if(s < n)
    {
        tmp.push_back(-1);
        return tmp;
    }
    
    for(int i = n; i > 1; i--)
    {
        q = s / i;
        answer[n - i] = q;
        s -= q;
    }
    
    answer[n - 1] = s;
    return answer;
}