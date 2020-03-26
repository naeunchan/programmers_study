#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    
    if(cacheSize == 0)
        return 5 * cities.size();
    
    for(int i = 0; i < cities.size(); i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto itr = find(cache.begin(), cache.end(), cities[i]);
        //cache miss
        if(itr == cache.end())
        {
            if(cache.size() == cacheSize)
            {
                string tmp = cache.front();
                cache.pop_front();
                cache.push_back(cities[i]);
                answer += 5;
            }
            else
            {
                cache.push_back(cities[i]);
                answer += 5;
            }
        }
        else
        {
            //cache hit
            answer += 1;
            string tmp = *itr;
            cache.erase(itr);
            cache.push_back(tmp);
        }
    }    

    return answer;
}