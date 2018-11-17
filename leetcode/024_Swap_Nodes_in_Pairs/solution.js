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
    let cur = head
    while(cur.next) {
      let temp = cur.next.next
      cur.next.next = cur
      cur.next = temp
      cur = cur.next
    }
    return head
}