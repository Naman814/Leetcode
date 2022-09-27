class Solution {
public:
    string pushDominoes(string s) {
        int n = s.length();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int time = 1;
        char prev = '.';
        for(int i=0;i<n;i++){
           if(s[i]=='L'){
               prev = 'L';
           }
           else if(s[i]=='R'){
               prev = 'R';
               time = 1;
               continue;
           }
           if(prev=='R' && s[i]=='.'){
               right[i] = time;
               time++;
           }  
        }
        time=1;
        prev='.';
        for(int i=n-1;i>=0;i--){
            if(s[i]=='R'){
                prev = 'R';
            }
            else if(s[i]=='L'){
                prev = 'L';
                time = 1;
                continue;
            }
            if(prev=='L' && s[i]=='.'){
                left[i] = time;
                time++;
            }
        }
        
        string ans = "";
        for(int i=0;i<n;i++){
            if(left[i]==right[i]){
                ans+=s[i];
            }
            else if(left[i]==0){
                ans+='R';
            }
            else if(right[i]==0){
                ans+='L';
            }
            else if(left[i]<right[i]){
                ans+="L";
            }
            else ans+="R";
        }
        
        return ans;
        
    }
};