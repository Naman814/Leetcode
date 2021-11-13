class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
     int n=temperatures.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(s.empty()){
            s.push(i);
            }
            else if(!s.empty() and temperatures[i]>temperatures[s.top()]){
                while(!s.empty() and temperatures[i]>temperatures[s.top()]){
                    ans[s.top()]=(i-s.top());
                    s.pop();
                }
                s.push(i);
            }
            else{
                s.push(i);
            }
        }
        return ans;
    }
};