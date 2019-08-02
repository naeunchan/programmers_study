#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end());
    string word = phone_book.front();
    int wordSize = word.size();
    int bookSize = phone_book.size();
    
    for(int i = 1; i < bookSize; i++)
    {
        int check = 0;
        for(int j = 0; j < wordSize; j++)
        {
            if(word[j] == phone_book[i][j])
                check++;
        }
        if(check == wordSize)
            return false;
    }
    return true;
}