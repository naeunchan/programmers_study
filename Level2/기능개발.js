function solution(progresses, speeds) {
    let answer = [];
    
    while(progresses.length > 0){
        let ans = 0;
        
        for(let i = 0; i < progresses.length; i++){
            progresses[i] += speeds[i];
        }
        
        while(progresses[0] >= 100){
            progresses.shift();
            speeds.shift();
            ans++;
        }
        
        if(ans > 0){
            answer.push(ans);
        }
    }
    return answer;
}