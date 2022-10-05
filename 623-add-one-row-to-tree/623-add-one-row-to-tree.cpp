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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return NULL;
        queue<TreeNode*> q;
        if(depth==1){
            TreeNode* newnode = new TreeNode(val);
            newnode->left = root;
            return newnode;
        }
        q.push(root);
        int height = 0;
        while(!q.empty()){
            int n = q.size();
            height++;
            for(int i=0;i<n;i++){
                auto curr = q.front();
                q.pop();
                if(height==depth-1){
                    TreeNode* left = new TreeNode(val);
                    left->left = curr->left;
                    curr->left = left;
                    TreeNode* right = new TreeNode(val);
                    right->right = curr->right;
                    curr->right = right;
                }
                else{
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                
            } 
        }
        return root;
    }
};