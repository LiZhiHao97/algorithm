/**
 * @param {string} s
 * @return {boolean}
 */
function isValid(s) {
    const a = []
    const validMap = {
      '{': '}',
      '[': ']',
      '(': ')'
    }
    for (let i = 0; i < s.length; i++) {
      if (s[i] === '{' || s[i] === '[' || s[i] === '(') {
        a.push(s[i])
      } else {
        if (s[i] !== validMap[a.pop()]) {
          return false
        }
      }
    }
    return !a.length
}

console.log(isValid("()"))