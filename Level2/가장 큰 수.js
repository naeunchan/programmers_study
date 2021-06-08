function solution(numbers) {
    const answer = numbers.toString()
        .split(",")
        .sort((a, b) => {
            if(a + b > b + a){
                return -1;
            }
            else if(a + b < b + a){
                return 1;
            }
        })
        .join("");
    
    return answer[0] === "0" ? "0" : answer;
}