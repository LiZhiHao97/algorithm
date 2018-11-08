/**
 * @param {number[]} nums
 * @return {number[][]}
 */
function threeSum(nums) {
  const results = []
  const sortedNums = nums.sort((a, b) => a - b)
  for (let i = 0; i < nums.length - 2; i++) {
    if (sortedNums[i] > 0) {
      return results
    }
    if (i > 0 && sortedNums[i] === sortedNums[i - 1]) {
      continue
    }
    let j = i + 1
      let k = sortedNums.length - 1
      while (k > j) {
        if (sortedNums[i] + sortedNums[j] + sortedNums[k] > 0) {
          k--
        } else if (sortedNums[i] + sortedNums[j] + sortedNums[k] < 0) {
          j++
        } else {
          results.push([sortedNums[i], sortedNums[j], sortedNums[k]])
          k--
          j++
          while(sortedNums[k] === sortedNums[k + 1] ) {
            k--
          }
          while(sortedNums[j] === sortedNums[j - 1]) {
            j++
          }
        }
      }
  }
  return results
}

const arr = [0, 0, 0]

console.log(threeSum(arr))