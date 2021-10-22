class Solution {
public:
    
     static bool cmp(pair<char, int> &a , pair<char, int> &b){
     return a.second>b.second; 
     }
 
     string frequencySort(string s) {
     unordered_map<char,int> m;
     vector<pair<char,int>> vp;
     for(auto x:s){
         m[x]++;
     }
     for(auto x:m){
         vp.push_back({x.first,x.second});
     }
     sort(vp.begin(),vp.end(),cmp);
     string ans="";
     for(auto x:vp){
         while((x.second)--){
             ans+=(x.first);
         }
     }
      return ans; 
    }
};