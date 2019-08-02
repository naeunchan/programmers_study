#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_multimap <string,int> c;
    int answer = 1;
    
    if(clothes.size() == 1)
        return 1;
    
    for(auto i : clothes)
    {
        auto tmp = c.find(i[1]);
        if(tmp == c.end())
            c.emplace(i[1],1);
        else
            ++tmp->second;
    }
    for(auto i : c)
        answer *= i.second + 1;
    return answer - 1;
}