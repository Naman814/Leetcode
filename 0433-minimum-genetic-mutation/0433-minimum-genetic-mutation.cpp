class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        if(st.count(end)==0) return -1;
        queue<string> q;
        q.push(start);
        int res = 0;
        unordered_set<string> vis;
        vis.insert(start);
        vector<char> avl{'A','C','G','T'};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
            auto curr = q.front();
            q.pop();
            if(curr == end) return res;
                
            for(int i=0;i<curr.length();i++){
                char orig = curr[i];
                for(int j=0;j<4;j++){
                    curr[i] = avl[j];
                    if(st.count(curr)){
                        if(!vis.count(curr)){
                            q.push(curr);
                            vis.insert(curr);
                        }
                    }
                }
                curr[i] = orig;
            }   
            }
            res++;
        }
        return -1;
    }
};