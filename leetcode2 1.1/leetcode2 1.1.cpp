/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode addTwoNumbers(struct ListNode l1, struct ListNode l2) {
    ListNode pre = new ListNode(0);
    ListNode cur = pre;
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
        int x = l1 == NULL ? 0 : l1.val;
        int y = l2 == NULL ? 0 : l2.val;
        int sum = x + y + carry;

        carry = sum / 10;
        sum = sum % 10;
        cur.next = new ListNode(sum);

        cur = cur.next;
        if (l1 != NULL)
            l1 = l1.next;
        if (l2 != NULL)
            l2 = l2.next;
    }
    if (carry == 1) {
        cur.next = new ListNode(carry);
    }
    return pre.next;
}


}