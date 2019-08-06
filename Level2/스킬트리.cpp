#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    while(!skill_trees.empty())
    {
        int check = 0;
        string s = skill_trees.back();
        auto index = find(s.begin(),s.end(),skill[0]);

        for(int i = 0; i < skill.size(); i++)
        {
            if(index > find(s.begin(),s.end(),skill[i]))
            {
                check = 0;
                break;
            }
            else
            {
                check++;
                index = find(s.begin(),s.end(),skill[i]);
            }
        }
        if(check > 0)
            answer++;
        skill_trees.pop_back();
    }
    return answer;
}