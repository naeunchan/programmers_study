const binarySearch = (stones, mid, k) => {
    let count = 0;
    
    for(let i = 0; i < stones.length; i++){
        if(stones[i] - mid <= 0){
            count++;
        } else{
            count = 0;
        }
        
        if(count >= 3){
            return true;
        }
    }
    
    return false;
}

const solution = (stones, k) => {
    let front = 0;
    let back = stones.length - 1;
    
    while(front <= back){
        const mid = Math.floor((front + back) / 2);
        
        if(binarySearch(stones, mid, k)){
            back = mid - 1;
        } else{
            front = mid + 1;
        }
    }
    
    return front;
}