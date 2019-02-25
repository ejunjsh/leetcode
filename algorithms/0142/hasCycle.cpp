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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode* walker = head;
        ListNode* runner = head;
        ListNode* entry = head;
        while(runner->next!=NULL && runner->next->next!=NULL) {
            walker = walker->next;
            runner = runner->next->next;
            if(walker==runner) {
                while(walker != entry) {               // found the entry location
                    walker  = walker->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};

// So, when the walker pointer and the runner pointer encounter in the cycle,
//  we can define a pointer "entry" that point to the head, this "entry" pointer moves one step each time so as the walker pointer. 
//  When this "entry" pointer and the walker pointer both point to the same location, this location is the node where the cycle begins.