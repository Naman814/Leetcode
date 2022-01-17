class Solution {
public:

    string tobinary(int num){
        string s="";
        while(num){
          s+=to_string(num%2);
          num=num/2;
        }
        return s;
    }
    int bitwiseComplement(int n) {
        string s="";
        if(n==0) return 1;
        s=tobinary(n);
        cout<<s;
        int res=0;
        
        // reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                res+=pow(2,i);
            }
        }
        return res;
    }
};