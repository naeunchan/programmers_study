function solution(array, commands) {
    let answer = [];
    
    for(let i = 0; i < commands.length; i++){
        let tmp = [];
        tmp = array.slice(commands[i][0] - 1, commands[i][1]);
        tmp = tmp.sort((a, b) => {
            return a - b;
        });
        answer.push(tmp[commands[i][2] - 1]);
    }
    
    return answer;
}