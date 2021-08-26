#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    map<string, map<string, int>> jobs;
    int max = 0;
        
    for(int i = 0; i < 5; i++){
        string token;
        string job;
        stringstream ss(table[i]);
        vector<string> v;
        map<string, int> lang;
        
        while(ss >> token){
            v.push_back(token);
        }
        
        job = v[0];
        
        for(int j = 1; j < 6; j++){
            lang[v[j]] = 6 - j;
        }
        
        jobs[job] = lang;
    }
    
    for(auto itr = jobs.begin(); itr != jobs.end(); itr++){
        string job = itr->first;
        int score = 0;
        
        for(int i = 0; i < languages.size(); i++){
            score += itr->second[languages[i]] * preference[i];
        }
        
        if(max < score){
            max = score;
            answer = job;
        }
    }
    
    return answer;
}