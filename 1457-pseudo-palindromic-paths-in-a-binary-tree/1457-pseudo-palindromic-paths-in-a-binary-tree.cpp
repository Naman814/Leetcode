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
    int ans=0;
    void solve(TreeNode* root,unordered_map<int,int>&mp,int res){
        if(!root) return;
        mp[root->val]++;
        if(mp[root->val]%2!=0) res++;
        else res--;
        solve(root->left,mp,res);
        solve(root->right,mp,res);
        if(!root->left && !root->right && res<=1){
            ans++;
        }
        mp[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        int res=0;
        solve(root,mp,res);
        return ans;
    }
};