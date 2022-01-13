class Solution {
public:
    bool checkRecord(string s) {
        int abscnt=0;
        int latecnt=0, maxilate=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='L'){
                latecnt++;
            }
            else{
                latecnt=0;
            }
            maxilate=max(maxilate,latecnt);
            if(s[i]=='A'){
                abscnt++;
            } 
        }
        if(abscnt<2 and maxilate<3){
            return true;
        }
        return false;
    }
};