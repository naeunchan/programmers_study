function solution(strings, n) {
  // 1. for문을 이용한 방법
  // for(let i = 0; i < strings.length; i++){
  //     for(let j = i + 1; j < strings.length; j++){
  //         if(strings[i][n] > strings[j][n]){
  //             [strings[i], strings[j]] = [strings[j], strings[i]];
  //         }
  //         else if(strings[i][n] === strings[j][n] && strings[i] > strings[j]){
  //             [strings[i], strings[j]] = [strings[j], strings[i]];
  //         }
  //     }
  // }
  // return strings;

  // 2.sort함수를 이용한 방법
  return strings.sort((s1, s2) =>
    s1[n] === s2[n] ? s1.localeCompare(s2) : s1[n].localeCompare(s2[n])
  );
}
