/**
 * @param {string} s
 * @return {number}
 */
function lengthOfLongestSubstring(s) {
  let maxLen = 0
  const map = {}
  for (let i = 0, j = 0; j < s.length; j++) {
    if (map[s[j]] !== undefined) {
      i = Math.max(map[s[j]], i)
    }
    maxLen = Math.max(maxLen, j - i + 1)
    map[s[j]] = j + 1
  }
  return maxLen
}

const str = "pwwkew"

console.log(lengthOfLongestSubstring(str))