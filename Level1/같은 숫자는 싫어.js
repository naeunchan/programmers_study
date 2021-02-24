function solution(arr)
{
    let answer = [];
    let pre = arr[0];
    
    answer.push(pre);
    
    for(let i = 1; i < arr.length; i++){
        if(arr[i] !== pre){
            answer.push(arr[i]);
            pre = arr[i];
        }
    }
    
    return answer;
    //return arr.filter((val,index) => val != arr[index+1]);
}