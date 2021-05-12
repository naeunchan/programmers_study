function solution(s) {
    let answer = s.length;
    
    for(let i = 1; i <= s.length / 2 + 1; i++){
        let count = 1;
        let tmp = 0;
        let str = s.substr(0, i);
        
        for(let j = i; j < s.length; j += str.length){
            if(str === s.substr(j, i)){
                count++;
            }
            else{
                if(count === 1){
                    tmp += str.length;
                }
                else{
                    tmp += count.toString().length + str.length;
                }
                str = s.substr(j, i);
                count = 1;
            }
        }
        
        if(count === 1){
            tmp += str.length;
        }
        else{
            tmp += count.toString().length + str.length;
        }
        
        answer = answer < tmp ? answer : tmp;
    }
    
    return answer;
}