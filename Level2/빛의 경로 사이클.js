function solution(grid) {
    const answer = [];
    const m = grid.length;
    const n = grid[0].length;
    const direct = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    const visited = Array.from({length: m}, () => Array.from({length: n}, () => Array(4).fill(false)));
        
    const go = (x, y, from) => {
        let nx = x;
        let ny = y;
        let to = from;
        
        switch(grid[x][y]){
            case "S":
                if(from === 0){
                    nx--;
                } else if(from === 1){
                    nx++;
                } else if(from === 2){
                    ny--;
                } else if(from === 3){
                    ny++;
                }
                break;
            case "L":
                if(from === 0){
                    ny--;
                    to = 2;
                } else if(from === 1){
                    ny++;
                    to = 3;
                } else if(from === 2){
                    nx++;
                    to = 1;
                } else if(from === 3){
                    nx--;
                    to = 0;
                }
                break;
            case "R":
                if(from === 0){
                    ny++;
                    to = 3;
                } else if(from === 1){
                    ny--;
                    to = 2;
                } else if(from === 2){
                    nx--;
                    to = 0;
                } else if(from === 3){
                    nx++;
                    to = 1;
                }
                break;
        }
        
        nx = nx < 0 ? m - 1 : nx === m ? 0 : nx;
        ny = ny < 0 ? n - 1 : ny === n ? 0 : ny;
        
        return [nx, ny, to];
    }
    
    const bfs = (x, y, d) => {
        const queue = [[x, y, d, 0]];
        
        while(queue.length){
            const [cx, cy, cd, len] = queue.shift();
            const [nx, ny, nd] = go(cx, cy, cd);
            
            if(visited[cx][cy][cd]){
                answer.push(len);
                
                return;
            }
            
            visited[cx][cy][cd] = true;
            queue.push([nx, ny, nd, len + 1]);
        }
    }
    
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            for(let k = 0; k < 4; k++){
                if(!visited[i][j][k]){
                    bfs(i, j, k);
                }
            }
        }
    }
    
    return answer.sort((a, b) => a - b);
}