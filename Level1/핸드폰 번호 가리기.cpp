#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    for(int i = 0; i < phone_number.size() - 4; i++)
        answer.push_back('*');
    answer += phone_number.substr(phone_number.size()-4);;

    return answer;
}