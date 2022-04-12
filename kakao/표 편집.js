class Node{
    constructor(val){
        this.val = val;
        this.prev = null;
        this.next = null;
    }
}

function solution(n, k, cmd) {
    const answer = Array.from({length: n}).fill("O");
    const node = Array.from({length: n}, () => new Node());
    const deleted = [];
    
    for(let i = 0; i < n; i++){
        node[i].val = i;
        
        if(i < n - 1){
            node[i].next = i + 1;
        }
        
        if(i > 0){
            node[i].prev = i - 1;
        }
    }
    
    for(let i = 0; i < cmd.length; i++){
        const splited = cmd[i].split(" ");
        let move = parseInt(splited[1]);
        
        switch(splited[0]){
            case "U":{
                while(move--){
                    k = node[k].prev;
                }
                
                break;
            }
                
            case "D":{
                while(move--){
                    k = node[k].next;
                }
                
                break;
            }
                
            case "C":{
                const {prev, next} = node[k];
                
                deleted.push(node[k]);
                
                if(node[prev]){
                    node[prev].next = next;
                }
                
                if(node[next]){
                    node[next].prev = prev;
                }
                
                k = next ? next : prev;
                
                break;
            }
                
            case "Z":{
                const restore = deleted.pop();
                const {val, prev, next} = restore;
                
                if(node[prev]){
                    node[prev].next = val;
                }
                
                if(node[next]){
                    node[next].prev = val;
                }
                
                break;
            }
        }
    }
    
    for(let i = 0; i < deleted.length; i++){
        const num = deleted[i].val;
        
        answer[num] = "X";
    }
    
    return answer.join("");
}