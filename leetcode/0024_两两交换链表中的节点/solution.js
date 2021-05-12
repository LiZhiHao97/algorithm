/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function swapPairs(head) {
  if (!head || !head.next) {
    return head
  }
  let newHead = head.next
  let cur = head
  while (cur && cur.next) {
    let twoStep = cur.next.next
    cur.next.next = cur
    cur.next = (twoStep && twoStep.next) ? twoStep.next : twoStep
    cur = twoStep
  }
  return cur
}