/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
function myPow(x, n) {
  if (n === 0) {
    return 1
  }
  let result = x
  let count = Math.abs(n)
  while (--count > 0) {
    result *= x
  }
  return n > 0 ? result : 1 / result
}

console.log(myPow(2.00000, -2))