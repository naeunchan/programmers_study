#include <string>
#include <vector>

using namespace std;
bool check[12][12] = {false, };
int answer = 0;

void dfs(int n, int row, int column, int queen);
bool isTrue(int n, int row, int column);

int solution(int n) {
    dfs(n, 0, 0, 0);
    
    return answer;
}

void dfs(int n, int row, int column, int queen)
{
    if(queen == n)
    {
        answer++;
        return;
    }
    
    for(int j = 0; j < n; j++)
    {
        if(isTrue(n, row, j))
        {
            check[row][j] = true;
            dfs(n, row + 1, j, queen + 1);
            check[row][j] = false;
        }
    }
}

bool isTrue(int n, int row, int column)
{
    //가로
    for(int i = 0; i < n; i++)
    {
        if(check[row][i] == true)
            return false;
    }
    
    //세로
    for(int i = 0; i < n; i++)
    {
        if(check[i][column] == true)
            return false;
    }
    
    //우측 상방 대각
    for(int i = row, j = column; i >= 0 && j < n; i--, j++)
    {
        if(check[i][j] == true)
            return false;
    }
    
    //우측 하방 대각
    for(int i = row, j = column; i < n && j < n; i++, j++)
    {
        if(check[i][j] == true)
            return false;
    }
    
    //좌측 상방 대각
    for(int i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        if(check[i][j] == true)
            return false;
    }
    
    //좌측 하방 대각
    for(int i = row, j = column; i < n && j >= 0; i++, j--)
    {
        if(check[i][j] == true)
            return false;
    }
    return true;
}