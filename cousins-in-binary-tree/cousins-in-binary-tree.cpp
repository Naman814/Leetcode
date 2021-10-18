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
    bool isCousins(TreeNode* root, int x, int y) {
      if(!root) return root;
      queue<TreeNode*> q;
      q.push(root);
      int res=false;
      while(!q.empty()){
         bool f1=false, f2=false;
          int n=q.size();
      for(int i=0;i<n;i++){
          TreeNode* temp=q.front();
          q.pop();
          if(temp->left and temp->right){
          if((temp->left->val==x and temp->right->val==y) || 
             (temp->left->val==y and temp->right->val==x)){
              return false;
          }
          }

          if(temp->val==x) f1=true;
          if(temp->val==y) f2=true;
          if(temp->left) q.push(temp->left);
          if(temp->right) q.push(temp->right);
      }
       if(f1 and f2){
           res=true;
           break;
       }
  }
         return res;
    }
};