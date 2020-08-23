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
    TreeNode* first=nullptr;
    TreeNode* second=nullptr;
    TreeNode* pre=new TreeNode(INT_MIN);
    void Traverse(TreeNode* root){
        if(!root) return;
        Traverse(root->left);
        if(!first&&pre->val>root->val){
            first=pre;
        }
        if(first&&pre->val>root->val){
            second=root;
        }
        pre=root;
        Traverse(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        Traverse(root);
        int temp=second->val;
        second->val=first->val;
        first->val=temp;
    }
};