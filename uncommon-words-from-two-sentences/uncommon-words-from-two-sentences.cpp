class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> m;
        vector<string> res;
        string temp="";
        for(int i=0;i<s1.length();i++){
            if(s1[i]==' '){
                m[temp]++;
                temp="";
            }else{
                temp+=s1[i];
            }
        }
        m[temp]++;
        temp="";
            for(int i=0;i<s2.length();i++){
            if(s2[i]==' '){
                m[temp]++;
                temp="";
            }else{
                temp+=s2[i];
            }
        }
        m[temp]++;
        
        for(auto x:m){
           // cout<<x.first<<" "<<x.second<<" ";
            if(x.second==1){
            res.push_back(x.first);
            }
                
        }
        return res;
    }
};