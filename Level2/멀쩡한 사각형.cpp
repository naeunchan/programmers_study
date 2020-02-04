#include <stdio.h>
using namespace std;

long long gcd(long long w, long long h);

long long solution(int w,int h)
{
	long long answer = (long long)w * (long long)h;
    long long g = gcd((long long)w, (long long)h);
    
	return answer - g * ((w / g) + (h / g) - 1);
}

long long gcd(long long w, long long h)
{
    return h ? gcd(h, w % h) : w;
}