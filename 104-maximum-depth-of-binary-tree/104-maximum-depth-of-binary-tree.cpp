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
    
    int solve(TreeNode* root){
    if(!root) return 0;
        int x=solve(root->left);
        int y=solve(root->right);
        return max(x,y)+1;
    
    }
    int maxDepth(TreeNode* root) {
        
        return solve(root);
        
    }
};