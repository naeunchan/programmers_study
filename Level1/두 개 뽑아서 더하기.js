const { support } = require("jquery");

function solution() {
  let n = 5;
  let lost = [2, 4];
  let reserve = [1, 3, 5];

  let answer = n - lost.length;

  lost = lost.sort((a, b) => {
    return a - b;
  });

  reserve = reserve.sort((a, b) => {
    return a - b;
  });

  for (let i = 0; (i = reserve.length); i++) {
    if (lost.indexOf(reserve[i]) !== -1) {
      answer++;
      lost.splice(lost.indexOf(reserve[i]), 1);
      reserve.splice(reserve.indexOf(reserve[i]), 1);
    }
  }

  while (lost.length > 0 && reserve.length > 0) {
    let front = reserve.find(lost[0] - 1);
    let back = reserve.find(lost[0] + 1);

    if (front !== undefined) {
      answer++;
      reserve.splice(reserve.indexOf(front), 1);
    } else if (back !== undefined) {
      answer++;
      reserve.splice(reserve.indexOf(back), 1);
    }
    lost.splice(0, 1);
  }

  return answer;
}
