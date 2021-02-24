function solution(numbers) {
  let answer = [];

  numbers.filter((val, index) => {
    for (let i = index + 1; i < numbers.length; i++) {
      answer.push(val + numbers[i]);
    }
  });

  answer = Array.from(new Set(answer)).sort((a, b) => {
    return a - b;
  });

  return answer;
}
