/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
    	if( head == NULL )
    		return NULL;
    	if(head->next == NULL)    
    	{	
    		TreeNode *root = new TreeNode( head->val );
    		return root;
    	}
    	ListNode *mid = head, *temp = head,*prev=head;
    	while( temp != NULL && temp->next != NULL ) 
    	{
            prev = mid;
    		mid = mid->next;
    		temp = temp->next->next;
    	}
    	TreeNode *root = new TreeNode(mid->val);
        prev->next=NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        
    	return root;
    }
};