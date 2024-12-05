class Solution {
public:
       void skipSpaces(string& s,int& n,int& pos){
        while(pos<n and s[pos]=='_')
            pos++;
    }
public:
    bool canChange(string start, string target) {
        int n=start.size();

        int first=0,second=0;
        int limit_idx = -1;
        while(first<n){
            //Skip all spaces
            skipSpaces(start,n,first);
            skipSpaces(target,n,second);
            
            if(first==n and second==n)          return true;
            if(start[first]!=target[second])    return false;

            if(start[first]=='L' and (second<=limit_idx or second>first))
                return false;
            else if(start[first]=='R' and first>second)
                return false;
    
            limit_idx = second;
            first++;
            second++;
        }
        //Skip leftover spaces (if any)
        skipSpaces(start,n,first);
        skipSpaces(target,n,second);

        return first==n && second==n;
    }
};