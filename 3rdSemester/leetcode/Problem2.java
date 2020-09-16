/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
       ListNode i1 = l1;
        ListNode i2 = l2;
        while (i1.next != null || i2.next != null) {
            if (i1.next == null)
                i1.next = new ListNode(0);
            if (i2.next == null)
                i2.next = new ListNode(0);
            i1 = i1.next;
            i2 = i2.next;
        }
        if (l1.next != null) {
            if (l1.val + l2.val >= 10) {
                ListNode d = new ListNode(l2.next.val+1, l2.next.next);
                ListNode next = addTwoNumbers(l1.next, d);
//                next = dek(next);
                return new ListNode(l1.val + l2.val - 10, next);
            }
            return new ListNode(l1.val + l2.val, addTwoNumbers(l1.next, l2.next));
        } else {
            if (l1.val + l2.val >= 10) {
                return new ListNode(l1.val + l2.val - 10, new ListNode(1));
            }
            return new ListNode(l1.val + l2.val);
        }
    }

    private static ListNode dek(ListNode next) {
        next.val++;
        if (next.val == 10) {
            if (next.next == null) {
                next = new ListNode(0, new ListNode(1));
            } else {
                dek(next.next);
            }
        }
        return next;
    }
}