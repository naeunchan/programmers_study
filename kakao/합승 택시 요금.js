const solution = (n, s, a, b, fares) => {
    let answer = 999999999;
    const cost = Array.from({length: n + 1}, () => Array(n + 1).fill(999999999));

    for(let i = 1; i <= n; i++){
        cost[i][i] = 0;
    }

    for(let i = 0; i < fares.length; i++){
        const A = fares[i][0];
        const B = fares[i][1];
        const fare = fares[i][2];

        cost[A][B] = fare;
        cost[B][A} = fare;
    }

    for(let k = 1; k <= n; k++){
        for(let i = 1; i <= n; i++){
            for(let j = 1; j <= n; j++){
                cost[i][j] = Math.min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for(let i = 1; i <= n; i++){
        answer = Math.min(answer, cost[s][i] + cost[i][a] + cost[i][b];
    }

    return answer;
}