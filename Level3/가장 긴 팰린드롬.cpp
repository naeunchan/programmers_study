#include <iostream>
#include <string>

using namespace std;
int solution(string s)
{
    int size = s.size(), mid = 0;
    
    if(size <= 1)
        return size;
    
    while(size > 1)
    {
        for(int i = 0; i <= s.size() - size; i++)
        {
            bool check = true;
            mid = size / 2;
            
            if(size % 2) // odd
            {
                for(int left = 0; left < mid; left++)
                {
                    if(s[left + i] != s[i + mid * 2 - left])
                    {
                        check = false;
                        break;
                    }
                }
            }
            else
            {
                for(int left = 0; left < mid; left++)
                {
                    if(s[left + i] != s[i + mid * 2 - 1 - left])
                    {
                        check = false;
                        break;
                    }
                }
            }    
            if(check)
                return size;
        }
        size--;
    }
}