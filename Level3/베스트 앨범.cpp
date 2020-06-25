#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

bool desc(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    multimap<string, pair<int, int>> mm;
    map<string, int> m;
    
    for(int i = 0; i < genres.size(); i++)
    {
        mm.insert(make_pair(genres[i], make_pair(plays[i], i)));
        m[genres[i]] += plays[i];
    }
    
    for(auto itr = m.begin(); itr != m.end(); itr++)
    {
        vector<pair<int, int>> v;
        for(auto i = mm.lower_bound(itr->first); i != mm.upper_bound(itr->first); i++)
            v.push_back(i->second);
        sort(v.begin(), v.end(), desc);
        mm.erase(mm.lower_bound(itr->first), mm.upper_bound(itr->first));
        
        for(int i = 0; i < 2; i++)
        {
            if(v.begin() + i == v.end())
                break;
            mm.insert(make_pair(itr->first, v[i]));
        }
    }
    
    while(!mm.empty())
    {
        int max = 0;
        string genre = "";
        
        for(auto itr = m.begin(); itr != m.end(); itr++)
        {
            if(max < itr->second)
            {
                max = itr->second;
                genre = itr->first;
            }
        }
        
        for(int i = 0; i < 2; i++)
        {
            if(mm.lower_bound(genre) == mm.end())
                break;
            answer.push_back(mm.lower_bound(genre)->second.second);
            mm.erase(mm.lower_bound(genre));
        }
        
        if(mm.find(genre) == mm.end())
            m.erase(genre);
    }
    return answer;
}