class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxi = 0, scores = 0, i=0, j = tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i++];
                scores++;
                maxi = max(maxi,scores);
            }
            else if(scores>0){
                scores--;
                power+=tokens[j--];
            }
            else break;
        }
        return maxi;
    }
};