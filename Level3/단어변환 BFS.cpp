#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> q, tmp;
    
    
    if(find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    q.push(make_pair(begin, 0));
    
    while(!q.empty())
    {
        int i = 0;
        pair<string, int> p;
        p = q.front();
        q.pop();
        
        if(p.first == target)
            return answer;
        
        for(i = p.second; i < words.size(); i++)
        {
            int count = 0;
            for(int j = 0; j < begin.size(); j++)
            {
                if(p.first[j] == words[i][j])
                    count++;
            }
            
            if(count == p.first.size() - 1)
                tmp.push(make_pair(words[i], i));
        }
        
        if(q.empty())
        {
            q = tmp;
            answer++;
            while(!tmp.empty())
                tmp.pop();
        }
    }
    
    return answer;
}