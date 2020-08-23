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
    TreeNode* first_node=nullptr;
    TreeNode* second_node=nullptr;
    TreeNode* pre_node=new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        while(!s.empty()||root!=nullptr){
            while(root!=nullptr){
                s.push(root);
                root=root->left;
            }
            root = s.top();
            s.pop();
            if(pre_node->val>root->val){
                if(first_node==nullptr)first_node=pre_node;
                if(first_node!=nullptr)second_node=root;
            }
            pre_node=root;
            root=root->right;
        }
        if(first_node!=nullptr&&second_node!=nullptr){
            int tmp=first_node->val;
            first_node->val=second_node->val;
            second_node->val=tmp;
        }
    }
};