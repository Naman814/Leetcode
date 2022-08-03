class MyCalendar {
public:
    unordered_map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       for(auto& [s1,e1] : mp){
           if(!(start>=e1 || end<=s1)) return false;
       }
       mp[start] = end;
       return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */