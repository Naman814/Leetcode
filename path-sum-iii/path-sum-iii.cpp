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
    
    void solve(TreeNode* root, int sum , vector<int> &v, int &ans){
        if(!root){
            return;
        }
        v.push_back(root->val);
        solve(root->left, sum, v, ans);
        solve(root->right, sum ,v, ans);
        int add=0;
        for(int i=v.size()-1;i>=0;i--){
            add+=v[i];
            if(add==sum){
                ans++;
            }
        }
       
        v.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        int res=0;
        vector<int> v;
        solve(root, targetSum, v, res);
        return res;
    }
};