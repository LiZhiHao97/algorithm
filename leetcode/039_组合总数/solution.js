/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
function combinationSum(candidates, target) {
  const result = []
  function dfs(current, start, sum) {
    if (sum === target) {
      result.push(current)
      return
    } else if (sum > target) {
      return
    }
    for (let i = startIndex; i < candidates.length; i++) {
      dfs([...current, candidates[i]], i, sum + candidates[i])
    }
  }
  dfs([], 0, 0)
  return result
}

console.log(combinationSum([1,2,3,5], 8))