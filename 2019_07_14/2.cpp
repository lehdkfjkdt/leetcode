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
int max_deepth=0;
vector<TreeNode*> deepest_leaves;
void FindMaxDeepth(TreeNode* root, int current_depth){
    if(!root) return;
    if(current_depth>max_deepth)max_deepth=current_depth;
    FindMaxDeepth(root->left,current_depth+1);
    FindMaxDeepth(root->right,current_depth+1);
}
void FindDeepestLeaves(TreeNode* root, int current_depth){
    if(!root) return;
    if(current_depth==max_deepth) deepest_leaves.push_back(root);
    FindDeepestLeaves(root->left,current_depth+1);
    FindDeepestLeaves(root->right,current_depth+1);
}
TreeNode* LCA(TreeNode* root){
    if(!root) return root;
    const auto iter=std::find(deepest_leaves.begin(),deepest_leaves.end(),root);
    if(iter!=deepest_leaves.end()) return *iter;
    TreeNode* L =LCA(root->left);
    TreeNode* R =LCA(root->right);
    if(L&&R) return root;
    return L?L:R;
}
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return root;
        max_deepth=0;
        deepest_leaves.clear();
        FindMaxDeepth(root, 0);
        FindDeepestLeaves(root,0);
        return LCA(root);
    }
};