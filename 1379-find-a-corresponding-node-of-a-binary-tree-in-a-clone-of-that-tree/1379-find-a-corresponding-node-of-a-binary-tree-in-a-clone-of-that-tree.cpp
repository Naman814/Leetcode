/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void preorder(TreeNode* node,vector<TreeNode*>&v){
        if(!node) return;
        v.push_back(node);
        preorder(node->left,v);
        preorder(node->right,v);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
       vector<TreeNode*> v1,v2;
       preorder(original,v1);
       preorder(cloned,v2);
       for(int i=0;i<v1.size();i++){
           if(v1[i]==target){
               return v2[i];
           }
       }
       return NULL;
    }
};