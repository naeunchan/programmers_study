#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int answer = 987654321;

void dfs(string current, string target, vector<string>& w, int index, vector<bool> check)
{
    if(current == target)
    {
        int ans = 0;
        for(int i = 0; i < w.size(); i++)
            if(check[i] == true)
                ans++;
        if(ans < answer)
            answer = ans;
        return;
    }
    
    
    
    for(int i = 0; i < w.size(); i++)
    {
        int count = 0;
        if(check[i] == false)
        {
            for(int j = 0; j < w[i].size(); j++)
                if(current[j] == w[i][j])
                    count++;
            if(count == current.size() - 1)
            {
                check[i] = true;
                dfs(w[i], target, w, i + 1, check);
                check[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) 
{   
    if(find(words.begin(), words.end(), target) == words.end())
        return 0;
    vector<bool> check(words.size(), false);
    dfs(begin, target, words, 0, check);
    return answer;
}