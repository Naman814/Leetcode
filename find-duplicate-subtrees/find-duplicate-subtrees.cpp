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
    
    string solve(TreeNode* root , unordered_map<string,int > &m , vector<TreeNode*> &res){
        if(!root) return "$";
        string s="";
          s+=to_string(root->val)+',';
        s+=solve(root->left,m,res);
        s+=solve(root->right,m,res);
      
        m[s]++;
        if(m[s]==2 ){
            res.push_back(root);
        }
        return s;
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        unordered_map<string,int> m;
        vector<TreeNode*> res;
        solve(root,m,res);
        return res;
    }
};