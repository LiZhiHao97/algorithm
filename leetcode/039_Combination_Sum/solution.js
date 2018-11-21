/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
function combinationSum(candidates, target) {
  const result = []
  candidates = candidates.sort((a, b) => a - b)
  for (let i = candidates.length - 1; i >= 0; i--) {
    if (candidates[i] === target) {
      result.push([candidates[i]])
      continue
    }
    let cur = [candidates[i]]
    let sum = candidates[i]
    let j = i
    while (j >= 0) {
      console.log(cur, candidates[j])
      if (sum + candidates[j] < target) {
        sum += candidates[j]
        cur.push(candidates[j])
      } else if (sum + candidates[j] > target) {
        j--
      } else if (sum + candidates[j] === target) {
        result.push([...cur, candidates[j]])
        j--
      }
    }
  }
  return result
}

console.log(combinationSum([1,2,3,5], 8))