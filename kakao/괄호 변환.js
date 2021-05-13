function isBalanced(string){
    const stack = [];
    
    string.forEach((element) => {
        if(element === ')' && stack[stack.length - 1] === '('){
            stack.pop();
        }
        else{
            stack.push(element);
        }
    });
    
    return stack.length === 0 ? true : false;
}

function reverse(string){
    let result = "";
    
    for(let i = 1; i < string.length - 1; i++){
        if(string[i] === "("){
            result += ")";
        }
        else{
            result += "(";
        }
    }
    
    return result;
}

function getString(p){
    const result = [];
    const stack = [];
    let left = 0;
    let right = 0;
    let index = 0;
    
    while(index < p.length){
        if(p[index] === '('){
            left++;
        }
        else{
            right++;
        }
        stack.push(p[index++]);
        
        if(left === right){
            if(isBalanced(stack)){
                result.push(stack.join(""));
                result.push(getString(p.substr(index)));
                break;
            }
            else{
                result.push("(");
                result.push(getString(p.substr(index)));
                result.push(")");
                result.push(reverse(stack.join("")));
                break;
            }
        }
    }
    
    return result.join("");
}

function solution(p) {
    const answer = getString(p);
    
    return answer;
}