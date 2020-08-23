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
    pair<TreeNode*, int> helper(TreeNode* root){
        if(root==nullptr) return make_pair(nullptr,0);
        pair<TreeNode*,int> L = helper(root->left);
        pair<TreeNode*,int> R = helper(root->right);
        if(L.second>R.second){
            return make_pair(L.first,L.second+1);
        }else if(L.second<R.second){
            return make_pair(R.first,R.second+1);
        }else{
            return make_pair(root,L.second+1);
        }
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }
};