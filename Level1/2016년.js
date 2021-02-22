function solution(a, b) {
    let answer = '';
    let month = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let day = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
    
    b += 4;
    
    for(let i = 1; i < a; i++){
        b += month[i];
    }
    
    answer = day[b % 7];
    
    return answer;
}