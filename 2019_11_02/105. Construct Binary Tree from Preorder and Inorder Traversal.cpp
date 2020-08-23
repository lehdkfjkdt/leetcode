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
    TreeNode* BuildHelp(const vector<int>& preorder, int start_1, int end_1,const vector<int>& inorder, int start_2, int end_2){
        if(end_1>=start_1&&end_2>=start_2){
            TreeNode* root = new TreeNode(preorder[start_1]);
            int index=start_2;
            for(;index<=end_2;++index){
                if(inorder[index]==preorder[start_1]){
                    break;
                }
            }
            int l_length= index-start_2;
            int r_length= end_2-index;
            root->left=BuildHelp(preorder,start_1+1,start_1+l_length,inorde r,start_2,index-1);
            root->right=BuildHelp(preorder,start_1+l_length+1,end_1,inorder,index+1,end_2);
            return root;
        }else{
            return NULL;
        }
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return BuildHelp(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};