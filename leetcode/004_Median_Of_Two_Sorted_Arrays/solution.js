/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
function findMedianSortedArrays(nums1, nums2) {
  let result
  let nums
  if (!(nums1.length && nums2.length)) {
    nums = nums1.length ? [...nums1] : [...nums2]
  } else if (nums1[nums1.length - 1] < nums2[0]) {
    nums = [...nums1]
    nums.splice(nums.length, 0, ...nums2)
  } else if (nums2[nums2.length - 1] < nums1[0]) {
    nums = [...nums2]
    nums.splice(nums.length, 0, ...nums1)
  } else {
    let shortNums
    if (nums1.length >= nums2.length) {
      nums = [...nums1]
      shortNums = [...nums2]
    } else {
      nums = [...nums2]
      shortNums = [...nums1]
    }
    let i = 0
    while (i < nums.length - 1 && shortNums.length) {
      if (shortNums[0] <= nums[i + 1]) {
        if (shortNums[0] >= nums[i]) {
          nums.splice(i + 1, 0, shortNums.shift())
        } else {
          nums.splice(0, 0, shortNums.shift())
        }
      }
      i++
    }
    shortNums.length ? nums.splice(i + 1, 0, ...shortNums) : null
  }
  const len = nums.length
  len % 2 ? result = nums[Math.floor(len / 2)] : result = (nums[len / 2 - 1] + nums[len / 2]) / 2
  return result
}

const nums1 = [1,2]
const nums2 = [-1,3]

console.log(findMedianSortedArrays(nums1, nums2))