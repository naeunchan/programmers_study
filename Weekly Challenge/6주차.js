function solution(weights, head2head) {
    const answer = [];
    const weightsSet = [...new Set(weights)];
    const weightsMap = new Map();
    const rating = [];
    const length = weights.length;
    let rank = 0;
    
    weightsSet.sort((a, b) => a - b);
    
    weightsSet.forEach((w) => weightsMap.set(w, rank++));
    
    for(let i = 0; i < length; i++){
        let rate = 0; // 승률
        let total = length; // 복서가 경기를 뛴 횟수
        let win = 0; // 복서가 다른 복서를 이긴 횟수
        let heavier = 0; // 자신보다 무거운 복서를 이긴 횟수
        let weightIndex = weightsMap.get(weights[i]); // 현재 복서의 몸무게 순위
        
        for(let j = 0; j < length; j++){
            if(head2head[i][j] === "W"){
                if(weights[i] < weights[j]){
                    heavier++;
                }
                win++
            } else if(head2head[i][j] === "N"){
                total--;
            }
        }
        
        if(total === 0){
            rate = 0;
        } else{
            rate = win / total;
        }
        
        rating.push([rate, heavier, weightIndex, i]);
    }
    
    rating.sort((a, b) => {
        if(a[0] === b[0]){
            if(a[1] === b[1]){
                if(a[2] === b[2]){
                    return a[3] - b[3];
                }
                
                return b[2] - a[2];
            }
            
            return b[1] - a[1];
        } else{
            return b[0] - a[0];
        }
    });
    
    rating.forEach((rank) => answer.push(rank[3] + 1));
    
    return answer;
}