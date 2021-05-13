function solution(s) {
    const answer = [];
    const set = [];
    let string = "";
    let array = [];
    
    for(let i = 0; i < s.length; i++){
        if(s[i] >= "0" && s[i] <= "9"){
            string += s[i];
        }
        else if(s[i] === "," || s[i] === "}"){
            if(string.length > 0){
                array.push(parseInt(string));
            }
            else{
                set.push(array);
                array = [];
            }
            string = "";
        }
    }
    set.sort((a, b) => a.length - b.length)
        .forEach((element) => {
        element.forEach((value) => {
            if(answer.indexOf(value) === -1){
                answer.push(value);
            }
        })
    });
    
    return answer;
}