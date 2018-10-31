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
function addTwoNumbers(l1, l2) {
    const resLinkedList = []
    let remain = 0
    while(l1 || l2 || remain) {
      let nodeResult = (l1 ? l1.val : 0) + (l2 ? l2.val : 0)
      nodeResult >= 10 ? remain = 1 : remain = 0
      l1 = l1.next || 0
      l2 = l2.next || 0
      resLinkedList.push(nodeResult % 10 + remain)
    }
    return resLinkedList
}