function solution(answers) {
    let answer = [];
    let A = [1, 2, 3, 4, 5];
    let B = [2, 1, 2, 3, 2, 4, 2, 5];
    let C = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    
    let aScore = 0, bScore = 0, cScore = 0;
    let aIndex = 0, bIndex = 0, cIndex = 0;
    
    for(let i = 0; i < answers.length; i++){
        if(A[aIndex++] === answers[i]){
            aScore++;
        }    
        if(B[bIndex++] === answers[i]){
            bScore++;
        }
        if(C[cIndex++] === answers[i]){
            cScore++;
        }
        
        if(aIndex === A.length){
            aIndex = 0;
        }
        if(bIndex === B.length){
            bIndex = 0;
        }
        if(cIndex === C.length){
            cIndex = 0;
        }
    }
    
    if(aScore === bScore && bScore === cScore){
        answer.push(1, 2, 3);
    }
    else if(aScore > bScore && aScore > cScore){
        answer.push(1);
    }
    else if(aScore === bScore && aScore > cScore){
        answer.push(1, 2);
    }
    else if(aScore === cScore && aScore > bScore){
        answer.push(1, 3);
    }
    else if(bScore > aScore && bScore > cScore){
        answer.push(2);
    }
    else if(bScore === cScore && bScore > aScore){
        answer.push(2, 3);
    }
    else if(cScore > aScore && cScore > bScore){
        answer.push(3);
    }
    
    return answer;
}