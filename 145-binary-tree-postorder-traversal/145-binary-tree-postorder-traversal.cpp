class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1,s2;
        vector<int> res;
        if(!root) return res;
        s1.push(root);
        while(!s1.empty()){
            root = s1.top();
            s2.push(s1.top());
            s1.pop();
            if(root->left){
                s1.push(root->left);
            }
            if(root->right){
                s1.push(root->right);
            }
        }
        while(!s2.empty()){
            res.push_back(s2.top()->val);
            s2.pop();
        }
        return res;
    }
};