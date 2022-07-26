class Solution {
public:
    TreeNode* solve(vector<int>&pre,vector<int>&ino,int left,int right,int &idx,unordered_map<int,int> &mp){
        if(left > right) return NULL;
        int pivot  = mp[pre[idx]];
        TreeNode * node = new TreeNode(pre[idx++]);
        node->left = solve(pre,ino,left,pivot-1,idx,mp);
        node->right = solve(pre,ino,pivot+1,right,idx,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
        int idx = 0, n = pre.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[ino[i]] = i;
        }
        return solve(pre,ino,0,pre.size()-1,idx,mp);
    }
};