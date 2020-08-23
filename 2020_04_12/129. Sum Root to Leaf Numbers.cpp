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
    int sum = 0;
    void PreOrder(TreeNode* root, int num){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr&&root->right==nullptr){
            sum+=(num*10+root->val);
        }
        PreOrder(root->left,num*10+root->val);
        PreOrder(root->right,num*10+root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        sum=0;
        PreOrder(root,0);
        return sum;
    }
};