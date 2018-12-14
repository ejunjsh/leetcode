/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = (int)lists.size();
        if(k==0) return NULL;
        if(k==1) return lists[0];
        return doMerge(lists, 0, (int)lists.size()-1);
    }


private:    
    ListNode* doMerge(vector<ListNode*>& lists, int left, int right) {
        if(left==right) return lists[left];
        else if(left+1==right) return mergeTwoLists(lists[left], lists[right]);
        ListNode* l1 = doMerge(lists, left, (left+right)/2);
        ListNode* l2 = doMerge(lists, (left+right)/2+1, right);
        return mergeTwoLists(l1, l2);
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};