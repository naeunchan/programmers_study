#include <string>
#include <algorithm>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int num[3], j = 0;
    char dart;
    
    for(int i = 0; i < dartResult.size(); i++)
    {
        dart = dartResult[i];
        
        if(dart >= '0' && dart <= '9')
        {
            if(dart == '1' && dartResult[i+1] == '0')
            {
                num[j] = 10;
                i++;
            }
            else
                num[j] = dart - 48;
        }
        else if(dart == 'S')
        {
            j++;
        }
        else if(dart == 'D')
        {
            num[j++] = pow(num[j], 2); 
        }
        else if(dart == 'T')
        {
            num[j++] = pow(num[j], 3);
        }
        else if(dart == '*')
        {
            if(j != 1)
            {
                num[j-2] *= 2;
                num[j-1] *= 2;
            }
            else
                num[j-1] *= 2;
        }
        else
        {
            num[j-1] *= -1;
        }
    }
    return num[0] + num[1] + num[2];
}