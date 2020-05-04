#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void move(int n, int from, int tmp, int to)
{
    if(n == 1)
    {
        answer.push_back({from, to});
    }
    else
    {
        move(n - 1, from, to, tmp);
        answer.push_back({from, to});
        move(n - 1, tmp, from, to);
    }
}

vector<vector<int>> solution(int n) {
    move(n, 1, 2, 3);
    return answer;
}