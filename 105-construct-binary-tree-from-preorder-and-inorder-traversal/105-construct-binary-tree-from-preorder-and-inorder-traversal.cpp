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
    TreeNode* solve(vector<int> &preorder,int prestart,int preEnd,vector<int> &inorder,
    int instart,int inEnd,unordered_map<int,int> &m){
        if(prestart > preEnd || instart > inEnd) return NULL;
        TreeNode * root = new TreeNode(preorder[prestart]);
        int elem = m[root -> val];
        int nElem = elem - instart;
        root -> left = solve(preorder, prestart + 1, prestart + nElem, inorder,
        instart, elem - 1, m);
        root -> right = solve(preorder, prestart + nElem + 1, preEnd, inorder, 
        elem + 1, inEnd, m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        int n = preorder.size();
        for(int i=0;i<n;i++) m[inorder[i]]=i;
        return solve(preorder,0,n-1,inorder,0,n-1,m);
    }
};