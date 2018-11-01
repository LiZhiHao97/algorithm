/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
function findMedianSortedArrays(nums1, nums2) {
  const len = nums1.length + nums2.length
  const half = Math.ceil(len / 2)
  const output = {
    prev: null,
    cur: null
  }
  while ((nums1.length + nums2.length) >= half) {
    output.prev = output.cur
    if (nums1.length === 0) {
      output.cur = nums2.shift()
    } else if (nums2.length === 0) {
      output.cur = nums1.shift()
    } else {
      if (nums1[0] >= nums2[0]) {
        output.cur = nums2.shift()
      } else {
        output.cur = nums1.shift()
      }
    }
  }
  
  if (len % 2 === 0) {
    return (output.prev + output.cur) / 2
  } else {
    return output.cur
  }
}

const nums1 = [1,2]
const nums2 = [-1,3]

console.log(findMedianSortedArrays(nums1, nums2))