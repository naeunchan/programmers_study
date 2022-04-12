class Node {
    constructor(value = ""){
        this.value = value;
        this.end = false;
        this.child = {};
        this.childLength = {};
    }
}

class Trie{
    constructor() {
        this.root = new Node();
    }
    
    insert(string){
        let currentNode = this.root;
        
        for(let i = 0; i < string.length; i++){
            const char = string[i];
            const length = currentNode.childLength[string.length];
            
            if(!currentNode.child[char]){
                currentNode.child[char] = new Node(currentNode.value + char);
            }
            
            currentNode.childLength[string.length] = length ? length + 1 : 1;
            currentNode = currentNode.child[char];
        }
        
        currentNode.end = true;
    }
    
    search(string){
        let currentNode = this.root;
        
        for(let i = 0; i < string.length; i++){
            const char = string[i];
            
            if(char === "?"){
                break;
            }
            
            if(currentNode.child[char]){
                currentNode = currentNode.child[char];
            } else{
                return 0;
            }
        }
        
        return currentNode.childLength[string.length] || 0;
    }
}

function solution(words, queries) {
    const answer = Array(queries.length).fill(0);
    const frontTrie = new Trie();
    const backTrie = new Trie();
    const check = new Map();
    
    const newWords = words.filter((word) => {
        if(check.has(word)){
            return false;
        }
        
        check.set(word, true);
        return true;
    });
    
    for(let i = 0; i < newWords.length; i++){
        const reverse = newWords[i].split("").reverse().join("");
        
        frontTrie.insert(newWords[i]);
        backTrie.insert(reverse);
    }
    
    for(let i = 0; i < queries.length; i++){
        const q = queries[i];
        
        if(q[0] !== "?"){
            answer[i] += frontTrie.search(q);
        } else{
            answer[i] += backTrie.search(q.split("").reverse().join(""));
        }
    }
    
    return answer;
}