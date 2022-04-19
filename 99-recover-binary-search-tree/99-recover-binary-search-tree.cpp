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
    TreeNode* f=NULL, *s=NULL, *prev=new TreeNode(INT_MIN);
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(!f and prev->val > root->val){
            f = prev;
        }
        if(f and prev->val > root->val){
            s = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = f->val;
        f->val = s->val;
        s->val = temp;
    }
};