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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null && l2 ==null)
            return null;

        ListNode res = new ListNode();
        ListNode iterationRes = res;

        while (l1 != null || l2 != null) {

            if (l1 == null) {
                iterationRes.val = l2.val;
                l2 = l2.next;
            } else if (l2 == null) {
                iterationRes.val = l1.val;
                l1 = l1.next;
            } else if (l1.val < l2.val) {
                iterationRes.val = l1.val;
                l1 = l1.next;
            } else {
                iterationRes.val = l2.val;
                l2 = l2.next;
            }

            if (l1 != null || l2 != null) {
                iterationRes.next = new ListNode();
                iterationRes = iterationRes.next;
            }
        }

        return res;
    }
}