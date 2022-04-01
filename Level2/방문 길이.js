function solution(dirs) {
    let answer = 0;
    const map = new Map();
    const direct = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    const queue = [];
    let x = 5;
    let y = 5;
    
    const rangeCheck = (x) => {
        if(x < 0){
            return 0;
        } else if(x > 10){
            return 10;
        }
        
        return x;
    }
    
    for(let i = 0; i < dirs.length; i++){
        let go = `${x}${y}`;
        let back = `${x}${y}`;
        const cx = x;
        const cy = y;
        
        if(dirs[i] === "U"){
            x = rangeCheck(x + direct[0][0]);
            y = rangeCheck(y + direct[0][1]);    
        } else if(dirs[i] === "D"){
            x = rangeCheck(x + direct[1][0]);
            y = rangeCheck(y + direct[1][1]);
        } else if(dirs[i] === "L"){
            x = rangeCheck(x + direct[2][0]);
            y = rangeCheck(y + direct[2][1]);
        } else if(dirs[i] === "R"){
            x = rangeCheck(x + direct[3][0]);
            y = rangeCheck(y + direct[3][1]);
        }
        
        if(cx !== x || cy !== y){
            go = `${go}${x}${y}`;
            back = `${x}${y}${back}`;

            if(!map.has(go) || !map.has(back)){
                answer++;
                map.set(go, true);
                map.set(back, true);
            }
        }
    }
    
    return answer;
}