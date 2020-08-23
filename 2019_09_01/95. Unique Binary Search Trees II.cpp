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
    vector<TreeNode*> Generate(int start, int end){
         vector<TreeNode*> ret;
        if(end<start){
            ret.push_back(nullptr);
        }else{
            for(int cur=start; cur<=end;cur++){
                vector<TreeNode*> lefts=Generate(start,cur-1);
                vector<TreeNode*> rights=Generate(cur+1,end);
                for(TreeNode* left: lefts){
                    for( TreeNode* right: rights){
                        TreeNode* cur_node=new TreeNode(cur);
                        cur_node->left=left;
                        cur_node->right=right;
                        ret.push_back(cur_node);
                    }
                }
            }
        }
        return ret;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return Generate(1,n);
    }
};