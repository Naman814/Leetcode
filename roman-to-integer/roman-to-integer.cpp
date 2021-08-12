class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> m;
        // char I , V, X, L, C, D, M;
        m['I']=1 ; m['V']=5; m['X']=10; m['L']=50; m['C']=100; m['D']=500;
        m['M']=1000;
        int n=s.length(), res=0;
        int temp=m[s[n-1]];
        res+=temp;
        for(int i=n-2;i>=0;i--){
        
            if(m[s[i]]==temp){
                res+=m[s[i]];
            }
            else if(m[s[i]]>temp){
                res+=m[s[i]];
                temp=m[s[i]];
            }
            else{
                res-=m[s[i]];
                temp=m[s[i]];
            }
        
        }
        
        return res;
    
    }
};