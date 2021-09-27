class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,bool> m;
        for(auto x:emails){
            string temp="", part1="" , part2=""; int i;
            temp=x;
            for(i=0;((i<temp.length()) && (temp[i]!='@')) ;i++){
                if(temp[i]=='+'){
                    while(temp[i]!='@'){
                        i++;
                    }
                    i--;
                }
                else if(temp[i]!='.' ){
                    part1+=temp[i];
                }
            }
            for(;i<temp.size();i++){
                part2+=temp[i];
            }
            string res=part1+part2;
            m[res]=true;
        }
        return m.size();
        
    }
};