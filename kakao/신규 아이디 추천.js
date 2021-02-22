function solution(new_id) {
    let temp = "";
    let ans = "";
    
    //1단계
    new_id = new_id.toLowerCase();
    
    //2단계
    for(let i = 0; i < new_id.length; i++){
        if((new_id[i] >= "a" && new_id[i] <= "z") || (new_id[i] >= "0" && new_id[i] <= "9") || (new_id[i] === "-") || (new_id[i] === "_") || (new_id[i] === ".")){
            temp += new_id[i];
        }
    }
    
    //3단계
    for(let i = 0; i < temp.length; i++){
        if(temp[i] === "."){
            let cnt = 0;
            
            for(let j = i + 1; j < temp.length; j++){
                if(temp[j] === "."){
                    cnt++;
                }
                else{
                    break;
                }
            }
            if(cnt > 0){
                ans += ".";
                i += cnt;
            }
            else{
                ans += temp[i];
            }
        }
        else{
            ans += temp[i];
        }
    }
    
    //4단계
    if(ans[0] === "."){
        ans = ans.slice(1);
    }
    if(ans[ans.length - 1] === "."){
        ans = ans.slice(0, -1);
    }
    
    //5단계
    if(ans.length === 0){
        ans = "a";
    }
    
    //6단계
    if(ans.length >= 16){
        ans = ans.slice(0, 15);
    }
    if(ans[ans.length - 1] === "."){
        ans = ans.slice(0, -1);
    }
    
    //7단계
    if(ans.length <= 2){
        while(ans.length < 3){
            ans += ans[ans.length - 1];
        }
    }
    
    return ans;
}