class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int start=0,end=1;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
      
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) {
                dp[i][i+1]=true;
                start=i;
                end=2;
            }   
        }
        
        for(int k=3;k<=n;k++){
            for(int i=0;i<=(n-k);i++){  
                int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(k>end){
                        end=k;
                        start=i;
                    }
                }
                
            }
            
        }
        string ans="";
        for(int i=start;i<(start+end);i++){
            ans+=s[i];
        }
        return ans;
        
    }
};