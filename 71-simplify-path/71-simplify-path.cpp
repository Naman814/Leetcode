class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string curr="";
        path+="/";
        for(int i=0;i<path.length();i++){
            char ch=path[i];
            if(ch=='/'){
                if(curr==".." and !s.empty()){
                    s.pop();
                }
                else if(curr!="" and curr!="." and curr!=".."){
                    s.push(curr);
                }
                curr="";
            }
            else{
                curr+=(ch);
            }
        }
        curr="";
        while(!s.empty()){
           curr =("/"+s.top())+curr;
            s.pop();
        }
        return curr==""?"/":curr;
    }
};