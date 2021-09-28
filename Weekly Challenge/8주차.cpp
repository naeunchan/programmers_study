#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int wMax = 0;
    int hMax = 0;
    
    for(int i = 0; i < sizes.size(); i++){
        sort(sizes[i].begin(), sizes[i].end());
    }
    
    for(int i = 0; i < sizes.size(); i++){
        wMax = wMax < sizes[i][0] ? sizes[i][0] : wMax;
        hMax = hMax < sizes[i][1] ? sizes[i][1] : hMax;
    }
    
    return wMax * hMax;
}