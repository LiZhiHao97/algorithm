/**
 * @param {number[]} nums
 * @return {number[][]}
 */
function permute(nums) {
  const result = []
  function dp(items, cur) {
    if (items.length === 1) {
      result.push([...cur, ...items])
      return
    } else {
      for(let i = 0; i < items.length; i++) {
        let newCur = [...cur, items[i]]
        const newItems = [...items]
        newItems.splice(i, 1)
        dp(newItems, newCur)
      }
    }
  }
  dp(nums, [])
  return result
}

const arr = [1,2,3]

console.log(permute(arr))