function solution(s) {
    let answer = '';
    let count = 0;
    
    for(let i = 0; i < s.length; i++){
        if(s[i] === " "){
            answer += " ";
            count = 0;
            continue;
        }
        
        if(count % 2){
            //odd
            answer += s[i].toLowerCase();
        }
        else{
            //even
            answer += s[i].toUpperCase();
        }
        count ++;
    }
    return answer;
}