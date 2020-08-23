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
    TreeNode* CreateBST(vector<int>& nums, int start_pos,int end_pos){
        if(start_pos>end_pos){
            return nullptr;
        }
        int root_index=(start_pos+end_pos)/2;
        TreeNode* root = new TreeNode(nums[root_index]);
        root->left=CreateBST(nums,start_pos,root_index-1);
        root->right=CreateBST(nums,root_index+1,end_pos);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return CreateBST(nums,0,nums.size()-1);
    }
};