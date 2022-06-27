class Solution {
public:
    int minPartitions(string n) {
        int res=n[0]-'0';
        for(int i=1;i<n.length();i++){
            res = max(res,n[i]-'0');
        }
        return res;
    }
};