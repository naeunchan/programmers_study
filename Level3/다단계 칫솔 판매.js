function solution(enroll, referral, seller, amount) {
    const answer = [];
    const map = new Map();
    const profit = new Map();
    
    const dfs = (parent, remain) => {
        if(parent === "-" || remain < 1){
            return;
        }
        const price = profit.get(parent) || 0;
        const val = map.get(parent);
        
        profit.set(parent, price + remain - Math.floor(remain * 0.1));
        
        dfs(val, Math.floor(remain * 0.1));
    }
    
    for(let i = 0; i < enroll.length; i++){
        const refer = referral[i];
        const enroller = enroll[i];
        
        map.set(enroller, refer);
    }
    
    for(let i = 0; i < seller.length; i++){
        const person = seller[i];
        const val = map.get(person) || [];
        const p = profit.get(person) || 0;
        let price = amount[i] * 100;
        
        profit.set(person, p + price - Math.floor(price * 0.1));
        dfs(val, Math.floor(price * 0.1));
    }
    
    for(let i = 0; i < enroll.length; i++){
        const val = profit.get(enroll[i]) || 0;
        
        answer.push(val);
    }
    
    return answer;
}