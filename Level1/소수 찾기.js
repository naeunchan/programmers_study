function solution(n) {
    let answer = 0;
    let prime = Array.from({length: n + 1}, () => false);
    
    for(let i = 2; i <= n; i++){
        
        if(!prime[i]){
            answer++;
            for(let j = i + i; j <= n; j += i){
                prime[j] = true;
            }
        }
    }
    
    return answer;
}