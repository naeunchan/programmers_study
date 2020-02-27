#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int check[101];

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int find(int node){
    if(node == check[node])
        return node;
    else
    {
        check[node] = find(check[node]);
        return check[node];
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i = 0; i < n; i++)
        check[i] = i;
    
    for(auto& cost : costs)
    {
        int start = find(cost[0]);
        int end = find(cost[1]);
        int v = cost[2];
        
        if(start != end)
        {
            answer += v;
            check[start] = end;
        }
    }

    return answer;
}