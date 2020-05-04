#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board[moves[0] - 1].size();
    stack<int> stk;
    
    for(int i = 0; i < moves.size(); i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(board[j][moves[i] - 1] != 0)
            {
                int tmp = board[j][moves[i] - 1];
                if(stk.empty() || stk.top() != tmp)
                    stk.push(tmp);
                else if(tmp == stk.top())
                {
                    answer += 2;
                    stk.pop();
                }
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    return answer;
}