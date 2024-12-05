class Solution {
public:
    void skipspaces(string &s,int &n,int &idx){
        while(idx<n and s[idx]=='_'){
            idx++;
        }
    }
    bool canChange(string s, string t) {
        int n = s.length();
        int first = 0;
        int second = 0;
        int prevIdx = -1;
        
        while(first<n){
        skipspaces(s,n,first);
        skipspaces(t,n,second);
        
        if(first==n and second==n) return true;
        if(s[first]!=t[second]) return false;
        
        if(s[first]=='L' and ( (second <= prevIdx)or (second > first) )){
            return false;
        }
        else if(s[first]=='R' and second < first){
            return false;
        }
         
         first++;
         second++;
    }
           skipspaces(s,n,first);
           skipspaces(t,n,second);
           
           return first==n and second==n;
           }
};