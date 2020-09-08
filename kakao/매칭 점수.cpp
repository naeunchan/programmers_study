#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<string, pair<pair<double, double>, pair<vector<string>, double>>> m;
vector<string> URL;

void find_url(string word, vector<string> pages)
{
    string og_url = "<meta property=\"og:url\" content=\"https://";
    string a_tag = "<a href=\"https://";
    
    for(int i = 0; i < pages.size(); i++)
    {
        string url = "", ext = "";
        pair<pair<double, double>, pair<vector<string>, double>> tmp;
        int url_index = pages[i].find(og_url) + 41;
        int body_start = pages[i].find("<body>") + 6;
        int index = 0;
        
        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
        
        while(pages[i][url_index] != '\"')
            url += pages[i][url_index++];
        
        index = pages[i].find(a_tag, body_start);
            
        while(index != string::npos)
        {
            index += 17;
            ext = "";

            while(pages[i][index] != '\"')
                ext += pages[i][index++];
            index = pages[i].find(a_tag, index + 1);
            tmp.first.second++; //외부 링크 개수 증가
            tmp.second.first.push_back(ext); //외부 링크 주소 벡터에 저장
        }
            
        index = pages[i].find(word, body_start);
        
        while(index != string::npos)
        {
            if(!(pages[i][index - 1] >= 'a' && pages[i][index - 1] <= 'z') && !(pages[i][index + word.size()] >= 'a' && pages[i][index + word.size()] <= 'z'))
                tmp.first.first++;
            index = pages[i].find(word, index + 1);
        }
        m[url] = tmp;
        URL.push_back(url);
    }
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    double current = 0;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    find_url(word, pages);
    
    for(auto itr : m)
    {
        for(int i = 0; i < itr.second.second.first.size(); i++)
        {
            string tmp = itr.second.second.first[i];
            if(m.find(tmp) != m.end())
                m[tmp].second.second += (itr.second.first.first / itr.second.first.second);
        }
    }
    
    for(int i = 0; i < URL.size(); i++)
    {
        m.find(URL[i])->second.second.second += m.find(URL[i])->second.first.first;
        
        if(current < m.find(URL[i])->second.second.second)
        {
            current = m.find(URL[i])->second.second.second;
            answer = i;
        }
    }
    
    return answer;
}