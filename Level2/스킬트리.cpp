#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i = 0; i < skill_trees.size(); i++)
    {
        int index = 0, cnt = 0;
        auto before = skill_trees[i].begin();
        
        while(1)
        {
            if(index == skill.size())
                break;
            
            auto itr = find(skill_trees[i].begin(), skill_trees[i].end(), skill[index]);
            
            if(before <= itr)
            {
                index++;
                cnt++;
                before = itr;
            }
            else
            {
                cnt = 0;
                break;
            }
        }
        if(cnt > 0)
            answer++;
        
    }
    return answer;
}