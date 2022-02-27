class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int res = 0;
        while(!q.empty()){
            int n = q.size();
            int currmin = q.front().second,leftidx,rightidx;
            for(int i=0;i<n;i++){
                long long int currid = q.front().second;
                TreeNode * temp = q.front().first;
                q.pop();
                if(i==0){
                    leftidx = currid;
                }
                if(i==n-1){
                    rightidx = currid;
                }
                if(temp->left){
                    q.push({temp->left,currid*2+1});
                }
                if(temp->right){
                    q.push({temp->right,currid*2+2});
                }
            }
            res = max(res,rightidx-leftidx+1);
        }
        return res;
    }
};