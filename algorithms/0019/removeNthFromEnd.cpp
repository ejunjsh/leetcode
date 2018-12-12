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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** dummy=&head;
        int length=0;
        ListNode* first=head;
        while(first!=NULL){
            length++;
            first = first->next;
        }
        
        length-=n;
        first = *dummy;
        
        if(length==0){
            return (*dummy)->next;
        }
        
        while(length>1){
            length--;
            first=first->next;
        }
        
        first->next=first->next->next;
        
        return (*dummy);
    }
};