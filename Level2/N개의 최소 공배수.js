function gcd(a, b){
    let c = 0;
    
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

function lcm(a, b){
    return a * b / gcd(a, b);
}

function solution(arr) {
    let answer = 0;
    
    arr.sort((a, b) => a - b);
    
    for(let i = 0; i < arr.length - 1; i++){
        answer = lcm(arr[i], arr[i + 1]);
        arr[i + 1] = answer;
    }
    
    return answer;
}