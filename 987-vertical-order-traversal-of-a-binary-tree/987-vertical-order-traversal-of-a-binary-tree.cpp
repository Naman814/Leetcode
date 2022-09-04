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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int hd = q.front().second.first;
            int lvl = q.front().second.second;
            q.pop();
            nodes[hd][lvl].insert(curr->val);
            if(curr->left){
                q.push({curr->left,{hd-1,lvl+1}});
            }
            if(curr->right){
                q.push({curr->right,{hd+1,lvl+1}});
            }
        }
        vector<vector<int>> res;
        for(auto x:nodes){
            vector<int> col;
            for(auto y:x.second){
                col.insert(col.end(),y.second.begin(),y.second.end());
            }
             res.push_back(col);
        }
        return res;
    }
};