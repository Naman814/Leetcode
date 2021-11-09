class Solution {
public:
    
     int maskWord(string word) {
        int mask = 0;
        for (auto c : word) mask |= (1 << c-'a');
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mask_freq;
        for (auto word : words) mask_freq[(maskWord(word))]++;
        
        vector<int> res;
        
        for (auto p : puzzles) {
            int mask = maskWord(p), submask = mask, first = (1 << p[0]-'a'), curr = 0;
            
            while (submask) {
                if (submask & first) curr += mask_freq[submask];
                
                submask = (submask-1) & mask;
            }
            
            res.push_back(curr);
        }
        return res;
    }
//   TLE 
    // vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
//     vector<int> res;
//     for(int i=0;i<puzzles.size();i++){
//         string s=puzzles[i];
//         unordered_map<char, bool> m;
//         for(auto x:s){
//             m[x]=true;
//         }
//         int ans=0;
//         for(int j=0;j<words.size();j++){
//             string word=words[j];
//             unordered_map<char, int> m2;
//         for(auto x:word){
//             m2[x]=true;
//         }
//         if(m2.find(s[0])!=m2.end()){
//             bool flag=true;
//             for(auto x : word){
//                 if(m.find(x)==m.end()){
//                     flag=false;
//                     break;
//                 }
//             }
//             if(flag==true){
//                 ans++;
//             }
//         }
            
//         }
//         res.push_back(ans);
//     }
//     return res;
        // }
};