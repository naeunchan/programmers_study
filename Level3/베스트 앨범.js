function solution(genres, plays) {
    const answer = [];
    const gSum = {};
    const gIndex = {};
    const len = genres.length;
    
    for(let i = 0; i < len; i++){
        const genre = genres[i];
        const play = plays[i];
        
        if(gSum[genre] === undefined){
            gSum[genre] = 0;
        }
        gSum[genre] += play;
        
        if(gIndex[genre] === undefined){
            gIndex[genre] = [];
        }
        gIndex[genre].push([play, i]);
    }
    
    const sortedGenre = [];
    const sortedPlay = [];
    
    for(const key in gSum){
        sortedGenre.push([key, gSum[key]]);
    }
    
    for(const arr in gIndex){
        gIndex[arr].sort((a, b) => b[0] - a[0]);
    }
    
    sortedGenre.sort((a, b) => b[1] - a[1]);
    
    for(const k of sortedGenre){
        const genre = k[0];
        
        if(gIndex[genre].length < 2){
            answer.push(gIndex[genre][0][1]);
        }
        else{
            answer.push(gIndex[genre][0][1]);
            answer.push(gIndex[genre][1][1]);
        }
    }
    
    return answer;
}