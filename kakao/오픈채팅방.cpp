#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> sentence;
    map<string,string> user;
    string enter = "님이 들어왔습니다.";
    string leave = "님이 나갔습니다.";
    
    for(int i = 0; i < record.size(); i++)
    {
        string split[3];
        string u;
        int j = 0;
        stringstream stream(record[i]);
        
        while(stream >> u)
            split[j++] = u;
        
        if(split[0] == "Enter")
        {
            user[split[1]] = split[2];
            answer.push_back(split[1]);
            sentence.push_back(enter);
        }
        else if(split[0] == "Leave")
        {
            answer.push_back(split[1]);
            sentence.push_back(leave);
        }
        else
        {
            user[split[1]] = split[2];
        }
    }
    
    for(int i = 0; i < answer.size(); i++)
    {
        answer[i] = user.find(answer[i])->second + sentence[i];
    }
    return answer;
}