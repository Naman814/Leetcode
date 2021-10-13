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
    TreeNode* solve(vector<int>&preorder, int &idx, int upper){
        if(idx>=preorder.size() || preorder[idx]>upper) return NULL;
        TreeNode* root= root=new TreeNode(preorder[idx++]);
        root->left=solve(preorder,idx,root->val);
        root->right=solve(preorder,idx, upper);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return solve(preorder,idx,INT_MAX);
    }
};