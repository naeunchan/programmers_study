function solution(priorities, location) {
    let answer = 0;
    
    while(1){
        let max = Math.max.apply(null, priorities);
        
        if(location === 0){
            if(max === priorities[location]){
                answer++;
                break;
            }
            else{
                priorities.push(priorities.shift());
                location = priorities.length - 1;
            }
        }
        else{
            if(max === priorities[0]){
                priorities.shift();
                answer++;
            }
            else{
                priorities.push(priorities.shift());
            }
            location--;
        }
    }
    
    return answer;
}