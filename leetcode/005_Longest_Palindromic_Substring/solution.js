/**
 * @param {string} s
 * @return {string}
 */
function longestPalindrome(s) {
  let result = ''
  let step = 0
  for(let i = 0; i < s.length; i = i + 1 + step) {
    let left = i - 1
    let right = i + 1
    while (s[i] === s[right]) {
      right++
    }
    if (right - i - 1 >= 2) {
      step = right - i - 1
    } else {
      step = 0
    }
    while (left >= 0 && right < s.length) {
      if (s[left] === s[right]) {
        left--
        right++
      } else {
        break
      }
    }
    if (right - left - 1 > result.length) {
      result = s.slice(left + 1, right)
    }
  }
  return result
}

const s = "bbbac"

console.log(longestPalindrome(s))