#include <string>
#include <vector>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "�輭���� ";
    int x = 0;
    for(int i = 0; i < seoul.size(); i++)
    {
        if(seoul[i] == "Kim")
        {
            x = i;
            break;
        }
    }
    answer += to_string(x);
    answer += "�� �ִ�";
    return answer;
}