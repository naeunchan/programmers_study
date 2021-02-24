function solution(s) {
    let answer = '';
    
    answer = s.length % 2 ? s.substr(s.length / 2, 1) : s.substr(s.length / 2 - 1, 2);
    
    return answer;
}