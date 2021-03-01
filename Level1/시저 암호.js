function solution(s, n) {
    let upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let lower = "abcdefghijklmnopqrstuvwxyz";
    let answer = "";
    
    for(let i = 0; i < s.length; i++){
        if(s[i] !== " "){
            answer += (upper.indexOf(s[i]) !== -1 ? upper[(upper.indexOf(s[i]) + n) % 26] : lower[(lower.indexOf(s[i]) + n) % 26])
        }
        else{
            answer += " ";
        }
    }
    return answer;
}