/**
 * @param {number} x
 * @return {number}
 */
function reverse(x) {
  const flag = x >= 0 ? true : false
  let str = x.toString()
  if (!flag) {
    str = str.substring(1)
  }
  let newNum = parseInt(str.split('').reverse().join(''), 10)
  flag ? null : newNum = -newNum
  if (newNum < -Math.pow(2, 31) || x > Math.pow(2, 31) - 1) {
    return 0
  }
  return newNum
}

console.log(reverse(1534236469))