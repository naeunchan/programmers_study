const solution = (id_list, report, k) => {
    const answer = [];
    const length = id_list.length;
    const count = new Map();
    const reportedUser = new Map();
    const idIndex = new Map();
    const saveReportId = Array.from({length}, () => []);
    
    for(let i = 0; i < length; i++){
        const id = id_list[i];
        
        idIndex.set(id, i);
    }
    
    for(let i = 0; i < report.length; i++){
        const [userId, targetId] = report[i].split(" ");
        
        if(!reportedUser.has(report[i])){
            const reportedCount = count.get(targetId) || 0;
            const userIdIndex = idIndex.get(userId);
            
            reportedUser.set(report[i], true);
            count.set(targetId, reportedCount + 1);
            saveReportId[userIdIndex].push(targetId);
        }
    }
    
    for(let i = 0; i < length; i++){
        let result = 0;
        
        for(let j = 0; j < saveReportId[i].length; j++){
            const targetId = saveReportId[i][j];
            
            if(count.get(targetId) >= k){
                result++;
            }
        }
        
        answer.push(result);
    }
    
    return answer;
}