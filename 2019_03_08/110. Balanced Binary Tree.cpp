/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct Result{
     bool is_balanced=false;
     int height=0;
 };
class Solution {
private:
    Result IsBalanced(TreeNode* root){
        if(root==nullptr){
            return {true,0};
        }
        Result l_result=IsBalanced(root->left);
        Result r_result=IsBalanced(root->right);
        if(!l_result.is_balanced||!r_result.is_balanced){
            return {false,std::max(l_result.height,r_result.height)+1};
        }
        return {std::abs(l_result.height-r_result.height)<=1,std::max(l_result.height,r_result.height)+1};
    }
public:
    bool isBalanced(TreeNode* root) {
        return IsBalanced(root).is_balanced;
    }
};