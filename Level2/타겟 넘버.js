function dfs(current, count, numbers, target){
    if(count === numbers.length){
        if(current === target){
            return 1;
        }
        return 0;
    }
    let answer = 0;
    
    answer += dfs(current + numbers[count], count + 1, numbers, target);
    answer += dfs(current - numbers[count], count + 1, numbers, target);
    
    return answer;
}

function solution(numbers, target) {
    let answer = 0;
    
    answer = dfs(0, 0, numbers, target);
    
    return answer;
}