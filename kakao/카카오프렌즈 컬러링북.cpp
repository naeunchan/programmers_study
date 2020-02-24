#include <vector>

using namespace std;

int bfs(int m, int n, int row, int column, vector<vector<int>>& picture, int target);

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(picture[i][j] == 0 || picture[i][j] == -1)
                continue;
            else
            {
                number_of_area++;
                int tmp = bfs(m, n, i, j, picture, picture[i][j]);
                if(tmp > max_size_of_one_area)
                    max_size_of_one_area = tmp;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int bfs(int m, int n, int row, int column, vector<vector<int>>& picture, int target)
{
    if(row < 0  || column < 0 || row == m || column == n || picture[row][column] != target)
        return 0;
    picture[row][column] = -1;
    int left = bfs(m, n, row, column - 1, picture, target);
    int right = bfs(m, n, row, column + 1, picture, target);
    int up = bfs(m, n, row - 1, column, picture, target);
    int down = bfs(m, n, row + 1, column, picture, target);
    
    return left + right + up + down + 1;
}