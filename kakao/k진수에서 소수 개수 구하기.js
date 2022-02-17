const solution = (n, k) => {
    let answer = 0;
    const transformed = [];
    
    const isPrime = (n) => {
        if(n <= 1){
            return false;
        }
        
        for(let i = 2; i <= Math.sqrt(n); i++){
            if(n % i === 0){
                return false;
            }
        }
        
        return true;
    }
    
    while(n){
        transformed.push(n % k);
        n = Math.floor(n / k);
    }
    
    transformed.reverse().join("").split("0").forEach((curr) => {
        if(curr && isPrime(curr)){
            answer++;
        }
    });
    
    return answer;
}