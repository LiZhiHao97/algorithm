/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function twoSum(nums, target) {
    let result1 = 0
    let result2 = null
    for (let i = 0; i < nums.length; i++) {
      for (let j = i + 1; j < nums.length; j++) {
        if (target === nums[result1] + nums[j]) {
          result2 = j
          return [result1, result2]
        }
      }
      result1 = i + 1
    }
}

function twoSum(nums, target) {
  const map = {}
  for (let i = 0; i < nums.length; i++) {
    if (map[target - nums[i]] != null) {
      return [map[target - nums[i]], i]
    }
    map[nums[i]] = i
  }
}

console.log(twoSum([2, 7, 11, 15], 9))