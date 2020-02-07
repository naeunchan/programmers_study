#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0, u = 0, l = 0, lu = 0;
    
    if(board.size() < 2 || board[0].size() < 2)
        return 1;
    
    for(int i = 1; i < board.size(); i++)
    {
        for(int j = 1; j < board[i].size(); j++)
        {
            if(board[i][j] == 1)
            {
                u = board[i - 1][j];
                l = board[i][j - 1];
                lu = board[i - 1][j - 1];

                board[i][j] = min(min(u, l), lu) + 1;

                if(answer < board[i][j])
                    answer = board[i][j];
            }
        }
    }

    return answer * answer;
}