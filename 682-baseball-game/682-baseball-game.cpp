class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                res.pop_back();
            }
            else  if(ops[i]=="D"){
                res.push_back(res.back()*2);
            }
            else if(ops[i]=="+"){
                res.push_back(res[res.size()-1]+res[res.size()-2]);
            }
            else {
                 res.push_back(stoi(ops[i]));
            }
        }
        int ans = accumulate(res.begin(),res.end(),0);
        return ans;
    }
};