function solution(n) {
    let answer = '';
    const number = [4, 1, 2];
    
    while(n){
        let remain = Math.floor(n % 3);
        n = Math.floor(n / 3);
        
        if(remain === 0){
            n -= 1;
        }
        
        answer = number[remain].toString() + answer;
    }
    return answer;
}