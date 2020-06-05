#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    
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
                cache.erase(cache.begin());
            answer += 5;
        }
        else //cache hit
        {
            answer++;
            cache.erase(itr);
        }
        cache.push_back(cities[i]);
    }
    return answer;
}