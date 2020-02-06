#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = n + 1;
    int num = bitset<20>(n).count();
    
    while(bitset<20>(answer).count() != num)
        answer++;
    return answer;
}