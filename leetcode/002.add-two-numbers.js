/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

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
var addTwoNumbers = function(l1, l2) {
    var head = new ListNode(null);
    var node = head;
    var last = null;

    while (l1 || l2) {
        var l1v = 0, l2v = 0;
        if (l1) {
            l1v = l1.val;
            l1 = l1.next;
        }

        if (l2) {
            l2v = l2.val;
            l2 = l2.next;
        }

        var val = parseInt( (l1v + l2v + last) % 10 );
        last = parseInt( (l1v + l2v + last) / 10 );
        console.log(l1v, l2v, val, last)
        head.next = new ListNode(val);
        head = head.next
    }

    if (last !== 0 ) {
        head.next = new ListNode(last);
        head = head.next
        head.next = null
    }

    return node.next;
};
