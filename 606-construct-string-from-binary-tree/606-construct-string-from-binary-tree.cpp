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
    void solve(string &str,TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right) {
             str+=to_string(root->val);
             return;
        } 
        str+=to_string(root->val);
        solve(str+="(",root->left);
        str+=")";
        if(!root->right) return;
        solve(str+="(",root->right);
        str+=")";
    }
    string tree2str(TreeNode* root) {
        string str="";
        solve(str,root);
        return str;
    }
    
};