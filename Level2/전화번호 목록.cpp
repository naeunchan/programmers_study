#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size(); i++)
    {
        string str = phone_book[i];
        int size = str.size();
        
        for(int j = i + 1; j < phone_book.size(); j++)
        {
            string tmp = phone_book[j].substr(0, size);
            if(str == tmp)
                return false;
        }
    }
    return answer;
}