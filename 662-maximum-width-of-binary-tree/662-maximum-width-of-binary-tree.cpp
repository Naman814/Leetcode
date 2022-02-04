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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int res =0;
        while(!q.empty()){
            int n =q.size();
            int mini = q.front().second;
            int first,last;
            for(int i=0;i<n;i++){
                long long int curr = q.front().second - mini;
                root = q.front().first;
                q.pop();
                if(i==0) first = curr;
                if(i==n-1) last = curr;
                if(root->left){
                    q.push({root->left,curr*2+1});
                }
                if(root->right){
                    q.push({root->right,curr*2+2});
                }
            }
            res = max(res, last-first+1);
        }
        return res;
    }
};