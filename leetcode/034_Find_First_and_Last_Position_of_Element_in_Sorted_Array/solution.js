/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function searchRange(nums, target) {
  let i = 0, j = nums.length - 1
  let result = [-1, -1]
  let count = 0
  while (i <= j && count < 2) {
    console.log(nums[i], nums[j])
    if (result[0] === -1) {
      if (nums[i] === target) {
        result[0] = i
        count++
      } else {
        i++
      }
    }

    if (result[1] === -1) {
      if (nums[j] === target) {
        result[1] = j
        count++
      } else {
        j--
      }
    }
  }
  return result
}

const nums = [5,7,7,8,8,10]

console.log(searchRange(nums, 8))