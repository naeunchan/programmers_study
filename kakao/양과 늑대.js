function solution(info, edges) {
    let answer = 1;
    const length = info.length;
    const graph = Array.from({length}, () => []);
    
    const dfs = (current, nextNodes) => {
        let [currentNode, sheep, wolves] = current;
        const newNextNodes = [...nextNodes];
        const index = newNextNodes.indexOf(currentNode);
        
        sheep += !info[currentNode];
        wolves += info[currentNode];
        answer = Math.max(answer, sheep);
        
        if(sheep === wolves){
            return;
        }
        
        if(graph[currentNode].length){
            newNextNodes.push(...graph[currentNode]);
        }
        
        newNextNodes.splice(index, 1);
        
        for(const nextNode of newNextNodes){   
            dfs([nextNode, sheep, wolves], newNextNodes);
        }
    }
    
    for(let i = 0; i < edges.length; i++){
        const [from, to] = edges[i];
        
        graph[from].push(to);
    }
    
    dfs([0, 0, 0], [0]);
    
    return answer;
}