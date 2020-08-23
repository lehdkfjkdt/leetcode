/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
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
    bool Helper(TreeNode* root, int target_sum, int current_sum){
        if(root){
            current_sum+=root->val;
            if(root->left==nullptr&&root->right==nullptr){
                return current_sum==target_sum;
            }
            if(root->left&&root->right){
                return Helper(root->left,target_sum,current_sum)||Helper(root->right,target_sum,current_sum);
            }else if(root->left){
                return Helper(root->left,target_sum,current_sum);
            }else{
                return Helper(root->right,target_sum,current_sum);
            }

        }else{
            return false;
        }
        
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return Helper(root,sum,0);
    }
};
// @lc code=end

