class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *cur = head, *right = NULL;
        while (cur) {
            if (cur->val != 9) right = cur;
            cur = cur->next;
        }
        if (!right) {
            right = new ListNode(0);
            right->next = head;
            head = right;
        }
        ++right->val;
        cur = right->next;
        while (cur) {
            cur->val = 0;
            cur = cur->next;
        }
        return head;
    }
};