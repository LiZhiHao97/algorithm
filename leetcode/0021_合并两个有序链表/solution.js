/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
function mergeTwoLists(l1, l2) {
    const resultList = new ListNode(0)
    let cur = resultList
    while (l1 && l2) {
      if (l1.val > l2.val) {
        cur.next = l2
        l2 = l2.next
      } else {
        cur.next = l1
        l1 = l1.next
      }
      cur = cur.next
    }
    while (l1) {
      cur.next = l1
      cur = cur.next
      l1 = n1.next
    }
    while (l2) {
      cur.next = l2
      cur = cur.next
      l2 = l2.next
    }
    return resultList.next
}