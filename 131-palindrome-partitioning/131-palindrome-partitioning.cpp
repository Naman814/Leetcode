class Solution {
public:
    
    
    
bool isPal(string s,int l,int h){

    while(l<h){
        if(s[l]!=s[h]){
            return false;
        }
        l++;
        h--;
    }

    return true;
}

void solve(vector<vector<string> > &ans,vector<string> &curr,int start,int n,string str){
    if(start>=n){
        ans.push_back(curr);
        return ;
    }

    for(int i=start;i<n;i++){
        if(isPal(str,start,i)){
            curr.push_back(str.substr(start,i-start+1));
            solve(ans,curr,i+1,n,str);
            curr.pop_back();
        }
          
    }

    
}

    vector<vector<string>> partition(string str) {
        
    int n=str.length();
    vector<vector<string> > ans;
    vector<string> curr;

    solve(ans,curr,0,n,str);
        
    return ans;
        
    }
};