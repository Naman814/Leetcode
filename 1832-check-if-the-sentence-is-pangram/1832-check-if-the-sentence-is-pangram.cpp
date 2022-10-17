class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s(sentence.begin(),sentence.end());
        return s.size() == 26;
    }
};