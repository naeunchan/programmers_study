#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    int size = commands.size();
    
    for(int i = 0; i < size; i++)
    {
        tmp.clear();
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++)
            tmp.push_back(array.at(j));
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp.at(commands[i][2]-1));
    }
    return answer;
}