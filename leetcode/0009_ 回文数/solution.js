/**
 * @param {number} x
 * @return {boolean}
 */
function isPalindrome(x) {
    if (x < 0 || (x !== 0 && x % 10 === 0)) {
      return false
    }
    let rev = 0
    while (x > rev) {
      rev = rev * 10 + x % 10
      x = Math.floor(x / 10)
    }
    return rev === x || Math.floor(rev / 10) === x
}

console.log(isPalindrome(-121))