function solution(arr, divisor) {
    let answer = arr.filter((val) => {
        if(!(val % divisor)){
            return val;
        }
    });
    
    return answer.length === 0 ? [-1] : answer.sort((a, b) => a - b);
}