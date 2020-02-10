#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0, a = 0, b = 0; //a = intersection, b = union
    vector<string> A, B;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for(int i = 0; i < str1.size() - 1; i++)
    {
        if((str1[i] >= 'a' && str1[i] <= 'z') && (str1[i + 1] >= 'a' && str1[i + 1] <= 'z'))
        {
            A.push_back(str1.substr(i, 2));
        }
    }
    for(int i = 0; i < str2.size() - 1; i++)
    {
        if((str2[i] >= 'a' && str2[i] <= 'z') && (str2[i + 1] >= 'a' && str2[i + 1] <= 'z'))
        {
            B.push_back(str2.substr(i, 2));
        }
    }
    
    if(A.empty() && B.empty())
        return 65536;
    
    b = A.size() + B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    if(A.size() <= B.size())
    {
        for(int i = 0; i < A.size(); i++)
        {
            auto itr = find(B.begin(), B.end(), A[i]);
            if(itr != B.end())
            {
                a++;
                B.erase(itr);
            }
        }
    }
    else
    {
        for(int i = 0; i < B.size(); i++)
        {
            auto itr = find(A.begin(), A.end(), B[i]);
            if(itr != A.end())
            {
                a++;
                A.erase(itr);
            }
        }
    }
    b -= a;
    
    if(b == 0)
        answer = 65536;
    else
        answer = (int)(((float)(a) / (float)(b)) * 65536);
    
    return answer;
}