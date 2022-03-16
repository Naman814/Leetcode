class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s; int i=0;
        for(auto val:pushed){
            s.push(val);
            while(s.size()>0 and s.top()==popped[i]){
                s.pop();
                i++;
            }
        }
        return s.empty()?true:false;
        
    }
};