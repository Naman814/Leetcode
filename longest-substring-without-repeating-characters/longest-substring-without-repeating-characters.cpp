class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set;
        if(s.size()==0)
            return 0;
        int cnt=0,max_cnt=1,k=0;
        for(int i=k;i<s.size();i++){
            if(set.find(s[i])==set.end()){
                cnt++;
                set.insert(s[i]);
            }
            else{
                set.clear();
                k++;
                i=k;
                set.insert(s[i]);
                cnt=1;
            }
            max_cnt=max(cnt,max_cnt);
             
        }
        
      
        return max_cnt; 
    }
};