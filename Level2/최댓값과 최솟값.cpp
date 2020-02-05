#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "", token = "";
    int minV, maxV;
    vector<int> num;
    
    for(stringstream str(s); (str >> token);)
        num.push_back(stoi(token));    
    
    minV = num[0];
    maxV = num[0];
    
    for(int i = 1; i < num.size(); i++)
    {
        minV = min(minV, num[i]);
        maxV = max(maxV, num[i]);
    }
    
    answer = to_string(minV) + ' ' + to_string(maxV);
    return answer;
}