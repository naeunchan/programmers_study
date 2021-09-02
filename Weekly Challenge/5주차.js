function solution(word) {
    const character = {
        "A": 0,
        "E": 1,
        "I": 2,
        "O": 3,
        "U": 4,
    };
    
    const distance = [781 ,156, 31, 6, 1];
    
    return word.split("").reduce((acc, value, index) => acc + (1 + (distance[index] * character[value])), 0);
}