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
    
    
    TreeNode* solve(vector<int> &inorder, int instrt, int inend ,vector<int> &postorder, int pstrt, int pend,                 unordered_map<int,int> &m){
        
        if(instrt > inend or pstrt > pend){
                return NULL;
        }
        TreeNode* root= new TreeNode(postorder[pend]);
        int idx = m[postorder[pend]];
        int numsleft = idx - instrt;
        root->left = solve(inorder, instrt, idx-1, postorder, pstrt, pstrt+numsleft-1, m);
        root->right = solve(inorder , idx+1, inend, postorder, pstrt+numsleft, pend-1 , m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int m=postorder.size();
        if(n!=m) return NULL;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return solve(inorder, 0, n-1, postorder , 0, m-1, mp);
    }
    
};