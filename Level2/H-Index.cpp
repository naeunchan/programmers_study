#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    int current = 0, up = 0, down = 0;
    sort(citations.begin(), citations.end());
    
    current = citations[size - 1];
    while(!current)
    {
        up = down = 0;
        for(int i = 0; i < size; i++)
        {
            if(current > citations[i])
                down++;
            else if(current <= citations[i])
                up++;
        }
        if(up >= current && down <= current)
            return current;
        current--;
    }
}