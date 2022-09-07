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
    int diff=INT_MAX;
    void solve(TreeNode* root,int &prev){
        if(!root) return;
        solve(root->left,prev);
        if(prev==-1){
            prev = root->val;
        }
        else{
           diff = min(diff,abs(prev-root->val));
           prev = root->val;
        }
        solve(root->right,prev);
        
        
    }
    int minDiffInBST(TreeNode* root) {
        int prev=-1;
        solve(root,prev);
        return diff;
    }
};