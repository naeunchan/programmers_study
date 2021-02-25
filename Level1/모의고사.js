function solution(answers) {
  let answer = [];
  let A = [1, 2, 3, 4, 5];
  let B = [2, 1, 2, 3, 2, 4, 2, 5];
  let C = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

  let aCount = answers.filter((val, index) => val === A[index % A.length]).length;
  let bCount = answers.filter((val, index) => val === B[index % B.length]).length;
  let cCount = answers.filter((val, index) => val === C[index % C.length]).length;
  let max = Math.max(aCount, bCount, cCount);

  if (max === aCount) {
    answer.push(1);
  }
  if (max === bCount) {
    answer.push(2);
  }
  if (max === cCount) {
    answer.push(3);
  }

  return answer;
}
