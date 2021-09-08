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
    void solve(TreeNode* root,int B,vector<int> v,bool &flag){
    if(!root) return;
    v.push_back(root->val);
    solve(root->left,B,v,flag);
    solve(root->right,B,v,flag);
    if(!root->left && !root->right){
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
        }
        if(sum==B){
            flag=true;
            return;
        }
    }

}
    bool hasPathSum(TreeNode* root, int targetSum) {
    vector<int> temp;
    bool flag=false;
    solve(root,targetSum,temp,flag);
    return flag;
        
    }
};