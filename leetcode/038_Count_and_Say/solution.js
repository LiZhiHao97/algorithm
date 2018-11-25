/**
 * @param {number} n
 * @return {string}
 */
function countAndSay(n) {
  let cur = '1'
  for (let i = 2; i <= n; i++) {
    let s = ''
    let len = 1
    for (let j = 0; j < cur.length; j++) {
      if (j < cur.length - 1 && cur[j + 1] === cur[j]) {
        len++
      } else {
        s += `${len}${cur[j]}`
        len = 1
      }
    }
    cur = s
  }
  return cur
}

console.log(countAndSay(6))