const solution = (fees, records) => {
    const answer = [];
    const [limitTime, feePerLimit, minute, feePerMinute] = fees;
    const inCars = new Map();
    const outCars = new Map();
    const carsNumber = [];
    
    for(const record of records){
        const [time, number, state] = record.split(" ");
        
        carsNumber.push(number);
        
        if(state === "IN"){
            inCars.set(number, time);
        } else{
            const [inHour, inMinute] = inCars.get(number).split(":");
            const [outHour, outMinute] = time.split(":");
            const inTotal = (parseInt(inHour) * 60) + parseInt(inMinute);
            const outTotal = (parseInt(outHour) * 60) + parseInt(outMinute);
            const savedTime = outCars.get(number) || 0;
            
            outCars.set(number, savedTime + (outTotal - inTotal));
            inCars.delete(number);
        }
    }
    
    for(const [key, value] of inCars){
        const [inHour, inMinute] = value.split(":");
        const savedTime = outCars.get(key) || 0;
        
        outCars.set(key, savedTime + ((60 * 23) + 59) - ((parseInt(inHour) * 60) + parseInt(inMinute)));
    }
    
    const orderedNumbers = [...new Set(carsNumber)].sort((a, b) => a - b);
    
    for(const number of orderedNumbers){
        const totalTime = outCars.get(number);
        const totalFee = totalTime <= limitTime ? feePerLimit : (feePerLimit + (Math.ceil((totalTime - limitTime) / minute) * feePerMinute));
        
        answer.push(totalFee);
    }
    
    return answer;
}