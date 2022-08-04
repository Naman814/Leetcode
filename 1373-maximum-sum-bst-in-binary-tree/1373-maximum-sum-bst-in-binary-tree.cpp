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

class Node{
    public:
    int mini, maxi, sz;
    Node(int mini,int maxi,int sz){
        this->mini = mini;
        this->maxi = maxi;
        this->sz = sz;
    }
};


class Solution {
private:
    int ans=0;
    Node solve(TreeNode* root){
        if(!root) return Node(INT_MAX,INT_MIN,0);
        Node lt = solve(root->left);
        Node rt = solve(root->right);
        int currsum = 0;
        if(lt.maxi < root->val && rt.mini > root->val){
            currsum = lt.sz + rt.sz + root->val;
            ans = max(ans,currsum);
            return Node(min(root->val,lt.mini), max(root->val,rt.maxi),currsum);
        }
        return Node(INT_MIN,INT_MAX,lt.sz+rt.sz);
    }
    public:
    int maxSumBST(TreeNode* root) {
         solve(root);
        return ans;
    }
};