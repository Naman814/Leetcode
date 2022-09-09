class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),cmp);
        int n = p.size();
        int res = 0;
        int mini = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(p[i][1] < mini){
                res++;
            }
            mini = max(mini,p[i][1]);
        }
        return res;
    }
};