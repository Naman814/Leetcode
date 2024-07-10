class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(int i=0;i<logs.size();++i){
            string temp = "";
            for(int j = logs[i].length()-1;j>=0;j--){
                if(logs[i][j]=='/'  || logs[i][j]=='.'){
                temp = logs[i][j] + temp;
                }
                else{
                    break;
                }
            }
            if(temp=="../" && cnt){
                cnt--;
            }
            else if(temp=="/"){
                cnt++;
            }
        }
          
        return cnt;
    }
};