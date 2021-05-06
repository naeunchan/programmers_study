function solution(n) {
    let tmp = [];
    let answer = "";
    
    while(n > 0){
        tmp.push(Math.floor(n % 10));
        n = Math.floor(n / 10);
    }
    tmp.sort((a, b) => b - a);
    
    tmp.forEach(val => {
        answer += val;
    })
    
    return parseInt(answer);
}