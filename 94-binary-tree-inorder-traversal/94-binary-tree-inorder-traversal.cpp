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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> q;
        vector<int> res;
        while(root || !q.empty()){
            if(root){
                q.push(root);
                root = root->left;
            }
            else{
                auto x = q.top();
                q.pop();
                res.push_back(x->val);
                root=x->right;
                
            }
        }
        return res;
    }
};