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
//     bool solve(TreeNode* root, TreeNode* mini, TreeNode* maxi){
//     if(!root) return true;
//     if((mini && root->val<mini->val) ||(maxi && root->val>maxi->val) ) return false;
//     return solve(root->left, mini, root) && solve(root->right , root ,maxi);    
// }
    bool solve(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(!root) return true;
    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        return false;
    return solve(root->left, minNode, root) && solve(root->right, root, maxNode);
}
    bool isValidBST(TreeNode* root) {
        return solve(root,NULL,NULL);
    }
};