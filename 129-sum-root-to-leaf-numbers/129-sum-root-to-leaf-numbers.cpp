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
    
   
int res = 0;
void solve(TreeNode* A,int sum){
    if(!A) return;
    sum = ((sum*10)+A->val);
    cout<<sum<<" ";
    solve(A->left,sum);
    solve(A->right,sum);
    if(!A->left && !A->right){
       res= res + sum;
    }
}
    int sumNumbers(TreeNode* root) {
        int sum=0;
        solve(root,sum);
        return res;
    }
};