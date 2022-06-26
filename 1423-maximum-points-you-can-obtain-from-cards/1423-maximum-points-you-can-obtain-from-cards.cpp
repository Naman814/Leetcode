class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int win=0,res=INT_MIN,sz=n-k;
        for(int i=0;i<sz;i++){
            win+=cardPoints[i];
        }
        res = total - win;
        for(int i=sz;i<n;i++){
            win-=cardPoints[i-sz];
            win+=cardPoints[i];
            res = max(res, total - win);   
        }
        return res;
    }
};