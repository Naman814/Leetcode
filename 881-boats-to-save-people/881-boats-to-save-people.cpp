class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int res=0;
        int l=0,h=people.size()-1;
        while(l<=h){
            if(people[l]+people[h]<=limit){
                l++;
                h--;
            }
            else{
                h--;
            }
            res++;
        }
        return res;
    }
};