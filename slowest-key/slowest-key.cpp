class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
          int big=releaseTimes[0];
        vector<pair<char,int>> vp;
        
        for(int i=0;i<releaseTimes.size();i++){
            if(i==0){
                vp.push_back({keysPressed[i],releaseTimes[0]});
                big=releaseTimes[0];
            }
            else{
                vp.push_back({ keysPressed[i] , releaseTimes[i]-releaseTimes[i-1]});
                big=max(big,releaseTimes[i]-releaseTimes[i-1]);
            }
        }
        sort(vp.begin(),vp.end());
        char res;
        for(auto it=vp.rbegin();it!=vp.rend();it++){
            if(it->second==big){
               res=(char)it->first;
                break;
            }
        }
        return res;
        
    }
};