class Solution {
public:
    
    static bool cmp(string &s1,string&s2){
        return (s1[1]=='=' && s2[1]=='!'); 
    }
    
    int findParent(int x,vector<int>&parent){
        if(x==parent[x]) return x;
        return parent[x] = findParent(parent[x],parent);
    }
    
    void unionn(int u,int v,vector<int>&parent,vector<int>&rank){
        int x = findParent(u,parent);
        int y = findParent(v,parent);
        if(rank[x] < rank[y]){
            parent[x] = y;
        }
        else if(rank[x] > rank[y]){
            parent[y] = x;
        }
        else{
            parent[x] = y;
            rank[y]++;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        vector<int> parent(26,0);
        vector<int> rank(26,0);
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
        sort(equations.begin(),equations.end(),cmp);
        for(int i=0;i<n;i++){
            int u = equations[i][0]-'a';
            int v = equations[i][3]-'a';
            if(equations[i][1]=='='){
                unionn(u,v,parent,rank);
            }
            else{
                if(findParent(u,parent)==findParent(v,parent)) return false;
            }
        }
        return true;
    }
};