class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
                sum = 0;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return sum;
    }
};