#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int rem;
    int num[3] = {4,1,2};
    
    while(n > 0)
    {
        rem = n % 3;
        n /= 3;
        
        if(rem == 0)
            n -= 1;
        answer = to_string(num[rem]) + answer;
    }
    return answer;
}