class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length(),i=0;
        for(i=0;i<n;i++){
            if(word[i]==ch) break;
        }
        if(i==n) return word;
        else reverse(word.begin(),word.begin()+i+1);
        return word;
    }
};