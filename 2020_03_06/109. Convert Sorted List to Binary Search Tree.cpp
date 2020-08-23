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
private:
    ListNode* head_=nullptr;
    TreeNode* Create(int start,int end){
        if(end<start){
            return nullptr;
        }
        const int middle = (start+end)/2;
        TreeNode* left=Create(start,middle-1);
        TreeNode* root = new TreeNode(head_->val);
        head_=head_->next;
        root->left=left;
        root->right=Create(middle+1,end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return nullptr;
        }
        head_ = head;
        int length=0;
        while(head){
            head=head->next;
            ++length;
        }
        return Create(0,length-1);
    }
};