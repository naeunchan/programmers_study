#include <string>
#include <vector>
#include <iostream>

using namespace std;

int win(int sum){
    if(sum == 6){
        return 1;
    }
    else if(sum == 5){
        return 2;
    }
    else if(sum == 4){
        return 3;
    }
    else if(sum == 3){
        return 4;
    }
    else if(sum == 2){
        return 5;
    }
    else{
        return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<bool> check(46, false);
    int zero_count = 0;
    int correct = 0;
    int sum = 0;
    
    for(int i = 0; i < 6; i++){
        check[win_nums[i]] = true;
    }
    
    for(int i = 0; i < 6; i++){
        if(check[lottos[i]]){
            correct++;
        }
        else if(lottos[i] == 0){
            zero_count++;
        }
    }
    
    sum = zero_count + correct;
    
    answer.push_back(win(sum));
    answer.push_back(win(correct)); 
    
    return answer;
}