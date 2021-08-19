function solution(price, money, count) {
    let sum = 0;
    
    while(count){
        sum += price * count--;
    }
    
    return money - sum < 0 ? sum - money : 0;
}