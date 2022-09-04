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
        int res=0;
        while(!q.empty()){
            int currMin = q.front().second;
            int sz = q.size();
            int lidx,ridx;
            for(int i=0;i<sz;i++){
                auto currNode = q.front().first;
                long long int curr = q.front().second - currMin;
                q.pop();
                if(i==0) lidx = curr;
                if(i==sz-1) ridx = curr;
                if(currNode->left) q.push({currNode->left,curr*2+1});
                if(currNode->right) q.push({currNode->right,curr*2+2});
            }
            res = max(res,ridx-lidx+1);
            
        }
        return res;
    }
};