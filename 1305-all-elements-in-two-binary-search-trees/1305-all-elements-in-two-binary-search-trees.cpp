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
    void preorder(TreeNode* head,vector<int> &res){
        if(!head) return;
        preorder(head->left,res);
        res.push_back(head->val);
        preorder(head->right,res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        preorder(root1,res);
        preorder(root2,res);
        sort(res.begin(),res.end());
        return res;
    }
};