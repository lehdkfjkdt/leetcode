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
void Inorder(TreeNode* root, vector<int>* ret){
        if(!root) return;
        Inorder(root->left,ret);
        ret->push_back(root->val);
        Inorder(root->right,ret);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        Inorder(root,&ret);
        return ret;
    }
};