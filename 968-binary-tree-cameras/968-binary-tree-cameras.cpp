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
    /*
    1-> covered with camera
    2-> Has camera
    0-> Not covered
    
    */
    int dfs(TreeNode* root,int &camera){
        if(!root) return 1;
        int left = dfs(root->left,camera);
        int right = dfs(root->right,camera);
        if(!left || !right) {
            camera++;
            return 2;
        }
        else if(left==2 || right==2) return 1;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int camera=0;
        return dfs(root,camera)==0 ? camera+1 : camera;
    }
};