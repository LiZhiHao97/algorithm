/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */

function twoSum(nums, target) {
  let low = 0
  let high = nums.length - 1
  while (low < high) {
    if (nums[low] + nums[high] < target) {
      low++
    } else if (nums[low] + nums[high] > target) {
      high--
    } else {
      return [low + 1, high + 1]
    }
  }
}

console.log(twoSum([2,7,11,15], 9))