function getString(str){
    const result = [];
    
    for(let i = 0; i < str.length; i++){
        result.push(str.substr(i, 2));
    }
    return result;
}

function isAlphabet(str){
    if(str[0] >= 'A' && str[0] <= 'Z' && str[1] >= 'A' && str[1] <= 'Z'){
        return true;
    }
    else{
        return false;
    }
}

function solution(str1, str2) {
    let answer = 0;
    const com1 = [];
    const com2 = [];
    let union = 0;
    let intersection = 0;
    
    getString(str1.toUpperCase()).forEach((e) => {
        if(isAlphabet(e)){
            com1.push(e);
        }
    });
    
    getString(str2.toUpperCase()).forEach((e) => {
        if(isAlphabet(e)){
            com2.push(e);
        }
    });
    
    union = com1.length + com2.length;
    
    if(com1.length >= com2.length){
        for(let i = 0; i < com2.length; i++){
            const index = com1.indexOf(com2[i]);
            
            if(index > -1){
                intersection++;
                com1.splice(index, 1);
            }
        }
    }
    else{
        for(let i = 0; i < com1.length; i++){
            const index = com2.indexOf(com1[i]);
            
            if(index > -1){
                intersection++;
                com2.splice(index, 1);
            }
        }
    }
    
    union -= intersection;
    
    return union === 0 ? 65536 : Math.floor((intersection / union) * 65536);
}