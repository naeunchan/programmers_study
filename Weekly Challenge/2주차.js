function grade(score){
    if(score >= 90){
        return "A";
    }
    else if(score >= 80 && score < 90){
        return "B";
    }
    else if(score >= 70 && score < 80){
        return "C";
    }
    else if(score >= 50 && score < 70){
        return "D";
    }
    else{
        return "F";
    }
}

function solution(scores) {
    const answer = [];
    const length = scores.length;
    
    for(let i = 0; i < length; i++){
        const currentScore = scores[i][i];
        let max = -1;
        let min = 101;
        let count = 0;
        let sum = 0;
        let numOfStudent = length;
        
        for(let j = 0; j < length; j++){
            max = max < scores[j][i] ? scores[j][i] : max;
            min = min > scores[j][i] ? scores[j][i] : min;
            count += scores[j][i] === currentScore ? 1 : 0;
            sum += scores[j][i];
        }
        
        if(count === 1){
            if(currentScore === max || currentScore === min){
                numOfStudent--;
                sum -= currentScore;
            }
        }
        
        answer.push(grade(sum / numOfStudent));
    }
    
    return answer.join("");
}