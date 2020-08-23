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
    int helper(TreeNode* root, bool father_selection,int val){
        if(root==nullptr){
            return 0;
        }
        if(father_selection){
            return max(helper(root->left,false,val),helper(root->right,false,val));
        }else{
            int select_max_val=max(helper(root->left,true,val+root->val),helper(root->right,true,val+root->val));
            int no_select_max_val=max(helper(root->left,false,val),helper(root->right,false,val);
            return max(select_max_val,no_select_max_val);
        }
    }
public:
    int rob(TreeNode* root) {
        return helper(root);
    }
};