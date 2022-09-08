/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeParent(TreeNode* A,map<TreeNode*,TreeNode*>&mp){
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        if(x->left){
            mp[x->left] = x;
            q.push(x->left);
        }
        if(x->right){
            mp[x->right] = x;
            q.push(x->right);
        }
    }
}
    
void burn(TreeNode* root,map<TreeNode*,TreeNode*>&mp,TreeNode* target,int k,vector<int>&res){
    int time = 0;
    queue<TreeNode*> q;
    map<TreeNode*,bool> vis;
    q.push(target);
    vis[target] = 1;
    while(!q.empty()){
        int sz = q.size();
        bool flag = 0;
        for(int i=0;i<sz;i++){
            auto x = q.front();
            q.pop();
            if(time==k){
                res.push_back(x->val);
            }
            if(x->left && !vis[x->left]){
                flag = 1;
                vis[x->left] = 1;
                q.push(x->left);
            }
            if(x->right && !vis[x->right]){
                flag = 1;
                vis[x->right] = 1;
                q.push(x->right);
            }
            if(mp[x] && !vis[mp[x]]){
                flag = 1;
                vis[mp[x]] = 1;
                q.push(mp[x]);
            }
        }
        if(time==k) break;
        if(flag) time++;
        
    }

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        map<TreeNode*,TreeNode*> mp;
        makeParent(root,mp);
        burn(root,mp,target,k,res);
        return res;
    }
};