const countDiffer = (word, target) => {
    let count = 0;
    
    for(let i = 0; i < word.length; i++){
        if(word[i] !== target[i]){
            count++;
        }
    }
    
    return count === 1 ? true : false;
}

const solution = (begin, target, words) => {
    let answer = 0;
    const queue = [];
    const map = new Map();
    
    queue.push(begin);
    
    while(queue.length){
        let size = queue.length;
        
        while(size--){
            const currentWord = queue[0];
            
            if(currentWord === target){
                return answer;
            }
            
            queue.shift();
            
            for(let i = 0; i < words.length; i++){
                const word = words[i];
                
                if(currentWord === word){
                    continue;
                }
                
                if(!map.get(currentWord + word) && !map.get(word + currentWord) && countDiffer(currentWord, word)){
                    queue.push(word);
                    map.set(currentWord + word, true);
                    map.set(word + currentWord, true);
                }
            }
        }
        
        answer++;
    }
    
    return 0;
}