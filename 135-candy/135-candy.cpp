class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        int ans = 0;
        vector<int> lt(n,1), rt(n,1);
        
        for(int i=1;i<n;i++){
            if(r[i] > r[i-1]){
                lt[i] = lt[i-1] + 1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(r[i+1] < r[i]){
                rt[i] = rt[i+1] + 1;
            }
        }
        
        for(int i=0;i<n;i++){
            ans += max(lt[i],rt[i]);
        }
        return ans;
    }
};