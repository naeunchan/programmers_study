#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string arr3;
    int i = 0, j = 0, tmp = 0;
    
    for(i = 0; i < n; i++)
    {
        arr3 = "";
        tmp = arr1[i] | arr2[i];
        while(tmp)
        {
            if(tmp % 2)
                arr3 += '#';
            else
                arr3 += ' ';
            tmp /= 2;
        }
        if(arr3.size() != n)
            while(arr3.size() != n)
                arr3 += ' ';
        reverse(arr3.begin(), arr3.end());
        answer.push_back(arr3);
    }
    return answer;
}