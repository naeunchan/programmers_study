function solution(n) {
    let answer = [];
    
    while(n > 0){
        answer.push(Math.floor(n % 10));
        n = Math.floor(n / 10);
    }
    
    return answer;
}