function solution(n,a,b)
{
    let answer = 0;
    
    while(1){
        a = parseInt((a / 2) + (a % 2));
        b = parseInt((b / 2) + (b % 2));
        answer++;
        
        if(a === b){
            return answer;
        }
    }
}