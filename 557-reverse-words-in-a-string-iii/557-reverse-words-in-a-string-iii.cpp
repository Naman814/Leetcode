class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word="",res="";
        while(getline(ss,word,' ')){
            reverse(word.begin(),word.end());
            res+=word+" ";
        }
        res.pop_back();
        return res;
    }
};