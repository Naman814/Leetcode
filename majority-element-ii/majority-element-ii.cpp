class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1, num2=-1, cnt1=0, cnt2=0, n=nums.size();
        vector<int> res;
        for(auto ele:nums){
            if(num1==ele){
                cnt1++;
            }
            else if(num2==ele){
                cnt2++;
            }
            else if(cnt1==0){
                num1=ele;
                cnt1=1;
            }
            else if(cnt2==0){
                num2=ele;
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        int x=0, y=0;
        for(auto ele : nums){
            if(ele==num1) x++;
            if(ele==num2) y++;
        }
        
        if(num1==num2) {
            res.push_back(num1);
            return res;
        }
        if(x>(n/3)) res.push_back(num1);
        if(y>(n/3)) res.push_back(num2);
        return res;
    }
};