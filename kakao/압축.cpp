#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> word;
    vector<string> a = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int count = 1, current_num = 27;
    
    for(int i = 0; i < 26; i++)
        word.insert(make_pair(a[i], i + 1));
    while(1)
    {
        string w = msg.substr(0, count);
        string c = msg.substr(count, 1);
        string wc = w + c;
        auto tmp_w = word.find(w);
        auto tmp_c = word.find(c);
        auto tmp_wc = word.find(wc);
        
        if(tmp_w != word.end())
        {
            if(tmp_wc != word.end())
            {
                if(count < msg.size())
                    count++;
            }
            else
            {    
                answer.push_back(tmp_w->second);
                word.insert(make_pair(wc, current_num++));
                msg.erase(0, count);
                count = 1;
            }
        }
        if(c == "\0")
        {
            answer.push_back(tmp_w->second);
            break;
        }
    }
    return answer;
}