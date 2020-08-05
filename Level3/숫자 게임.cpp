#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int aIndex = 0, bIndex = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    if(A.back() > B.front())
        return 0;
    else
    {
        for(int i = 0; i < A.size(); i++)
        {
            if(A[aIndex] < B[bIndex])
            {
                bIndex++;
                answer++;
            }
            aIndex++;
        }
    }
    return answer;
}