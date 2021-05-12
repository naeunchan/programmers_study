function solution(maps) {
    let answer = 1;
    const visited = maps;
    const queue = [];
    const directX = [-1, 1, 0, 0];
    const directY = [0, 0, -1, 1];
    const n = maps.length;
    const m = maps[0].length;
    
    queue.push([0, 0]);
    visited[0][0] = 0;
    
    while(queue.length > 0){
        const size = queue.length;
        
        for(let i = 0; i < size; i++){
            const [x, y] = queue.shift();
            
            for(let j = 0; j < 4; j++){
                const nx = x + directX[j];
                const ny = y + directY[j];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] === 1){
                    if(nx == n - 1 && ny == m - 1){
                        return ++answer;
                    }
                    queue.push([nx, ny]);
                    visited[nx][ny] = 0;
                }
            }    
        }
        answer++;
    }
    
    return -1;
}