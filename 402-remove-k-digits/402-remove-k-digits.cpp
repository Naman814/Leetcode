class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(n==k) return "0";
        stack<int> s;
        string ans="";
        for(int i=0;i<n;i++){
            int val = num[i]-'0';
                while(!s.empty() and val<s.top() and k>0){
                    s.pop();
                    k--;
                }
                if(s.empty() and val==0) continue;
            s.push(val);
        }
         while(k && !s.empty())
        {
            --k;
            s.pop();
        }
        while(!s.empty()){
            string temp = to_string(s.top());
            ans = temp + ans;
            s.pop();
        }
        return ans = ans==""? "0" : ans;
    }
};