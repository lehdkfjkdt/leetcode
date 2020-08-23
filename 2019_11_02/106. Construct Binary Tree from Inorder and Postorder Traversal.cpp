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
    TreeNode* buildHelp(const vector<int>& inorder,int start_1,int end_1, const vector<int>& postorder, int start_2, int end_2){
        if(end_1>=start_1&&end_2>=start_2){
            TreeNode* root = new TreeNode(postorder[end_2]);
            int index=start_1;
            for(;index<=end_1;++index){
                if(inorder[index]==postorder[end_2]){
                    break;
                }
            }
            int l_length=index-start_1;
            int r_length=end_1-index;
            root->left=buildHelp(inorder,start_1,index-1,postorder,start_2,start_2+l_length-1);
            root->right=buildHelp(inorder,index+1,end_1,postorder,start_2+l_length,end_2-1);
            return root;
        }else{
            return NULL;
        }
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildHelp(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};