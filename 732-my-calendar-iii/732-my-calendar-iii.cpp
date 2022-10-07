class MyCalendarThree {
public:
    map<int,int> mp;
    int maxi=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int cnt = 0;
        for(auto x:mp){
            cnt+=x.second;
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */