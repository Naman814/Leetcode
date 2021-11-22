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
      int maxLeft(TreeNode *root){
        if(root->right==NULL){
            return root->val;
        }
        return maxLeft(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
		//if root has both children
        else{
            if(root->left!=NULL && root->right!=NULL){
				// find max on left side of root
                int max=maxLeft(root->left);
                root->val=max;
               root->left=deleteNode(root->left,max);
                return root;
                
            }
			//if root has only one child
            else if(root->right==NULL){
                TreeNode *curr=root->left;
                delete root;
                return curr;
            }
             else if(root->left==NULL){
                TreeNode *curr=root->right;
                delete root;
                return curr;
            }
            else{
                delete root;
                return NULL;
            }
        }
        return root;
   
    }
};