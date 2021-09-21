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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        vector<pair<int,int>> vp;
        q.push(root);
        int lvl=0;
        while(!q.empty()){
            lvl++;
            int sum=0;
            int n=q.size();
            for(int i=0;i<n;i++){
            TreeNode* temp=q.front();
             sum+=temp->val;
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
            q.push(temp->right);
              
                }
            }
           vp.push_back({sum,lvl});
        }
        int maxi=INT_MIN, ans=0; 
       for(auto x:vp){
          
         if(maxi<x.first){
           maxi=x.first;
           ans=x.second;
            }
              }
        return ans;
    }
};