const solution = (play_time, adv_time, logs) => {
    let time = 0;
    let sum = 0;
    
    const calculateSecond = (h, m, s) => (h * 3600) + (m * 60) + s;
    
    const splitAndConvert = (time) => time.split(":").map((v) => parseInt(v));
    
    const [ph, pm, ps] = splitAndConvert(play_time);
    const [ah, am, as] = splitAndConvert(adv_time);
    const playTime = calculateSecond(ph, pm, ps);
    const advTime = calculateSecond(ah, am, as);
    const imos = Array(playTime + 1).fill(0);
    
    const timeFormat = (time) => {
        const h = Math.floor(time / 3600);
        const m = Math.floor(time % 3600 / 60);
        const s = time % 3600 % 60;
        
        return `${h < 10 ? "0" : ""}${h}:${m < 10 ? "0" : ""}${m}:${s < 10 ? "0" : ""}${s}`
    }
    
    if(playTime === advTime){
        return "00:00:00";
    }
    
    for(const log of logs){
        const [start, end] = log.split("-");
        const [sh, sm, ss] = splitAndConvert(start);
        const [eh, em, es] = splitAndConvert(end);
        const startTime = calculateSecond(sh, sm, ss);
        const endTime = calculateSecond(eh, em, es);
        
        imos[startTime]++;
        imos[endTime]--;
    }
    
    for(let i = 1; i <= playTime; i++){
        imos[i] += imos[i - 1];
    }
    
    for(let i = 1; i <= playTime; i++){
        imos[i] += imos[i - 1];
    }
    
    sum = imos[advTime - 1];
    
    for(let i = advTime - 1; i < playTime; i++){
        const aTime = imos[i] - imos[i - advTime];
        
        if(sum < aTime){
            sum = aTime;
            time = i - advTime + 1;
        }
    }
    
    return timeFormat(time);;
}
