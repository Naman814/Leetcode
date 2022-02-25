class Solution {
public:
    int compareVersion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        int i=0,j=0;
        while(i<n || j<m){
            string temp1="", temp2="";
            while(i<n and s1[i]!='.'){
            if(temp1.size()==0 and s1[i]=='0'){
                i++;
                continue;
            }
            temp1+=s1[i++];
            }
            while(j<m and s2[j]!='.'){
            if(temp2.size()==0 and s2[j]=='0'){
                j++;
                continue;
            }
            temp2+=s2[j++];
            }
            if(temp1.length()>temp2.length()){
                return 1;
            }
            else if(temp1.length() < temp2.length()){
                return -1;
            }
            else{
                int check=temp1.compare(temp2);
                if(check>0){
                    return 1;
                }
                else if(check<0) return -1;
            }
            i++;
            j++;
        }
        return 0;
    }
};