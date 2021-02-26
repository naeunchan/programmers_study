function solution(s) {
    let len = s.split("")
            .filter(val => val >= "0" && val <= "9")
            .length;
    return ((s.length === 4) || (s.length === 6)) && s.length === len ? true : false;
}