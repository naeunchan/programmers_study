function solution(n, lost, reserve) {
    let answer = n - lost.length;

    lost = lost.sort((a, b) => {
        return a - b;
    });

    reserve = reserve.sort((a, b) => {
        return a - b;
    });

    for(let i = reserve.length - 1; i >= 0; i--){
        if(lost.indexOf(reserve[i]) !== -1){
            answer++;
            lost.splice(lost.indexOf(reserve[i]), 1);
            reserve.splice(reserve.indexOf(reserve[i]), 1);
        }
    }
    
    while(lost.length > 0 && reserve.length > 0){
        if(reserve.indexOf(lost[0] - 1) !== -1){
            answer++;
            reserve.splice(reserve.indexOf(lost[0] - 1), 1);
        }
        else if(reserve.indexOf(lost[0] + 1) !== -1){
            answer++;
            reserve.splice(reserve.indexOf(lost[0] + 1), 1);
        }
        lost.splice(0, 1);
    }
    
    return answer;
}