/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==nullptr){
            return ret;
        }
        queue<TreeNode*> cur;
        cur.push(root);
        queue<TreeNode*> next;
        vector<int> cur_vec;
        while(!cur.empty()){
           TreeNode* cur_node = cur.front();
           cur.pop();
           cur_vec.push_back(cur_node->val);
           if(cur_node->left!=nullptr){
               next.push(cur_node->left);
           }
           if(cur_node->right!=nullptr){
               next.push(cur_node->right);
           }
           if(cur.empty()){
               cur=next;
               while (!next.empty())
               {
                   next.pop();
               } 
               ret.push_back(cur_vec);
               cur_vec.clear();
           }
        }
        return ret;  
    }
};
// @lc code=end

