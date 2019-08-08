#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0, size = name.size();
    int left = 0, right = 0;
    int front = 0, back = size - 1;
    int fw = 0, bw = 0, current = 0;
    string cmp = "";
    
    for(int i = 0; i < size; i++)
        cmp += 'A';
    
    while(cmp != name)
    {
        if(name[current] == 'A')
        {
            while(name[front] == 'A')
                front++;
            while(name[back] == 'A')
                back--;
            if(front < current)
                right = front + size - current;
            else
                right = front - current;
            if(back < current)
                left = current - back;
            else
                left = size - back + current;
            if(right <= left)
            {
                current = front;
                answer += right;
            }
            else
            {
                current = back;
                answer += left;
            }
        }
        else
        {
            fw = name[current] - 'A';
            bw = 'Z' - name[current] + 1;
            answer += fw <= bw ? fw : bw;
            name.replace(current,1,"A");
        }
    }
    
    return answer;
}