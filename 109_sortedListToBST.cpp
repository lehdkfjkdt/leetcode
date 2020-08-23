/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    TreeNode* helper(vector<ListNode*>& vec,int start,int end){
        if(start>end){
            return nullptr;
        }
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(vec[mid]->val);
        root->left=helper(vec,start,mid-1);
        root->right=helper(vec,mid+1,end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* cur=head;
        while(cur!=nullptr){
            vec.push_back(cur);
            cur=cur->next;
        }
        return helper(vec,0,vec.size()-1);
    }
};