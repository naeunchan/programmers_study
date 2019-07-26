#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    char * DAY[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int month[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    int m;
    b +=4;
    for(m = 1; m < a; m++)
        b += month[m];
    answer = DAY[b % 7];
    return answer;
}