function solution(n) {
    let answer = 0;
    let start = 1;
    
    while(start <= n){
        let tmp = 0;
        
        for(let i = start; tmp <= n; i++){
            tmp += i;
            
            if(tmp === n){
                answer++;
            }
        }
        
        start++;
    }
    
    return answer;
}