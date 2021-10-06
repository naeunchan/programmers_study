const binarySearch = (d, mid, budget) => {
    let sum = 0;
    
    for(let i = 0; i <= mid; i++){
        sum += d[i];
        
        if(sum > budget){
            return true;
        }
    }
    
    return false;
}

const solution = (d, budget) => {
    let front = 0;
    let back = d.length - 1;
    
    d.sort((a, b) => a - b);
    
    while(front <= back){
        const mid = Math.floor((front + back) / 2);
        
        if(binarySearch(d, mid, budget)){
            back = mid - 1;
        } else{
            front = mid + 1;
        }
    }
    
    return front;
}