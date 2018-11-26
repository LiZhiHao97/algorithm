/**
 * @param {string} digits
 * @return {string[]}
 */
function letterCombinations(digits) {
  const result = []
  const map = {
    '2': ['a', 'b', 'c'],
    '3': ['d', 'e', 'f'],
    '4': ['g', 'h', 'i'],
    '5': ['j', 'k', 'l'],
    '6': ['m', 'n', 'o'],
    '7': ['p', 'q', 'r', 's'],
    '8': ['t', 'u', 'v'],
    '9': ['w', 'x', 'y', 'z']
  }
  if (!map[digits[0]]) {
    return []
  }
  function dp(str, cur) {
    let btn = map[str[0]]
    let newStr = str.slice(1)
    for(let i = 0; i < btn.length; i++) {
      if (newStr.length) {
        dp(newStr, `${cur}${btn[i]}`)
      } else {
        result.push(`${cur}${btn[i]}`)
      }
    }
  }
  dp(digits, '')
  return result
}

const digits = '27'

console.log(letterCombinations(digits))