/**
 * @param {string[]} strs
 * @return {string}
 */
function longestCommonPrefix(strs) {
    if (!strs.length) {
      return ""
    }
    let base = strs[0]
    let result = ""
    let count = 1
    while (count <= base.length) {
      let flag = true
      let current = base.substring(0, count)
      for (item of strs) {
        if (current !== item.substring(0, count)) {
          return result
        }
      }
      result = current
      count ++
    }
    return result
}

const strs = ["a"]

console.log(longestCommonPrefix(strs))