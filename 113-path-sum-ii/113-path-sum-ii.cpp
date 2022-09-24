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
void findPaths(TreeNode*root,int target,vector<vector<int>>&res,vector<int>&temp){
        if(!root) return;
        temp.push_back(root->val);
        target-=root->val;
        findPaths(root->left,target,res,temp);
        findPaths(root->right,target,res,temp);
        if((!root->left && !root->right) && target==0){
            res.push_back(temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        findPaths(root,targetSum,res,temp);
        return res;
    }
};