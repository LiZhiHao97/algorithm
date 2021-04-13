/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function search(nums, target) {
  let i = 0, j = nums.length - 1
  while(i <= j) {
    if (nums[i] === target) {
      return i
    }
    if (nums[j] === target) {
      return j
    }
    i++
    j--
  }
  return -1
}

const nums = [4,5,6,7,0,1,2]

console.log(search(nums, 0))