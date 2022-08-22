/**
 * @param {number[]} nums
 * @return {number}
 */
 var lengthOfLIS = function(nums) {
  if (nums.length === 0) return 0

  const dp = Array(nums.length)
  let maxLen = 1
  dp[0] = 1

  for (let i = 1; i < nums.length; i++) {
    dp[i] = 1

    for (let j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        dp[i] = Math.max(dp[i], dp[j] + 1)
      }
    }
    maxLen = Math.max(maxLen, dp[i])
  }

  return maxLen
};

console.log(lengthOfLIS([10,9,2,5,3,7,101,18]))
console.log(lengthOfLIS([0,1,0,3,2,3]))
console.log(lengthOfLIS([7,7,7,7,7,7,7]))