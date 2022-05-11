class Solution {
public:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int countVowelStrings(int n) {
        int count = 0;
        countVowelStringsHelper(n, ' ', count);
        return count;
    }
    void countVowelStringsHelper(int n, char last, int &count){
        if(n == 0){
            count++;
        }
        else{
            for(auto e: vowels){
                if(last <= e){
                    countVowelStringsHelper(n-1, e, count);
                }
            }
        }
    }
};