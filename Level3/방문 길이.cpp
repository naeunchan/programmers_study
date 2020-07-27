#include <string>
#include <iostream>
#include <map>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    bool visited[11][11] = {false, };
    int x = 5, y = 5;
    multimap<int, pair<int, pair<int, int>>> mm;
    
    visited[5][5] = true;
    
    for(int i = 0; i < dirs.size(); i++)
    {
        int tmpX = x, tmpY = y;
        
        if(dirs[i] == 'U')
            y++;
        else if(dirs[i] == 'D')
            y--;
        else if(dirs[i] == 'L')
            x--;
        else if(dirs[i] == 'R')
            x++;
        
        if(x < 0 || x > 10 || y < 0 || y > 10)
        {
            x = tmpX;
            y = tmpY;
            continue;
        }
        
        if(visited[x][y] == false)
        {
            visited[x][y] = true;
            answer++;
            mm.insert(make_pair(x, make_pair(y, make_pair(tmpX, tmpY))));
            mm.insert(make_pair(tmpX, make_pair(tmpY, make_pair(x, y))));
        }
        else
        {
            bool check = false;
            auto find_key = mm.find(x);
            for(auto itr = mm.lower_bound(find_key->first); itr != mm.upper_bound(find_key->first); itr++)
            {
                if(itr->second.first == y && itr->second.second.first == tmpX && itr->second.second.second == tmpY)
                {
                    check = true;
                    break;
                }
            }
            
            if(!check)
            {
                check = false;
                auto find_key = mm.find(tmpX);
                for(auto itr = mm.lower_bound(find_key->first); itr != mm.upper_bound(find_key->first); itr++)
                {
                    if(itr->second.first == tmpY && itr->second.second.first == x && itr->second.second.second == y)
                    {
                        check = true;
                        break;
                    }
                }
                if(!check)
                {
                    answer++;
                    mm.insert(make_pair(x, make_pair(y, make_pair(tmpX, tmpY))));
                    mm.insert(make_pair(tmpX, make_pair(tmpY, make_pair(x, y))));
                }
            }   
        }
    }
    return answer;
}