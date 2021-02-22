function solution(n) {
    let answer = 0;
    let tmp = "";
    
    while(n > 0){
        tmp += new String(n % 3);
        n = parseInt(n / 3);
    }
    
    for(let i = tmp.length - 1; i >= 0; i--){
        answer += 3 ** (tmp.length - 1 - i) * parseInt(tmp[i]);
    }
    
    return answer;
}