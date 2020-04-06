#include <string>
#include <vector>

using namespace std;
int answer = 987654321;
    
void dfs(int N, int number, int count, int sum)
{
    if(count > 8)
        return;
    else if(count <= 8 && sum == number)
    {
        answer = min(answer, count);
        return;
    }
    
    int tmp = 0;
    for(int i = 0; i < 8; i++)
    {
        tmp = tmp * 10 + N;
        dfs(N, number, count + i + 1, sum + tmp);
        dfs(N, number, count + i + 1, sum - tmp);
        
        if(sum != 0)
        {
            dfs(N, number, count + i + 1, sum * tmp);
            dfs(N, number, count + i + 1, sum / tmp);
        }
    }
}

int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if(answer <= 8)
        return answer;
    return -1;
}