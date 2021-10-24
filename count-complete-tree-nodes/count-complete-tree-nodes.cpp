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
     int leftheight(TreeNode* root){
     int lh=0;
     if(!root) return 0;
     int x=leftheight(root->left);
     return x+1;
 }
      int rightheight(TreeNode* root){
     if(!root) return 0;
     int x=rightheight(root->right);
     return x+1;
 }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int x=leftheight(root);
        int y=rightheight(root);
        if(x==y){
            return pow(2,x)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
};