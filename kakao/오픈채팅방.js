function solution(record) {
    const answer = [];
    const users = {};
    
    record.forEach((element) => {
        const [state, id, nickname] = element.split(" ");

        if(state === "Enter" || state === "Change"){
            users[id] = nickname;
        }
    });
    
    record.forEach((element) => {
        const [state, id] = element.split(" ");
        if(state === "Enter"){
            answer.push(`${users[id]}님이 들어왔습니다.`);
        }
        else if(state === "Leave"){
            answer.push(`${users[id]}님이 나갔습니다.`);
        }
    });
    
    return answer;
}