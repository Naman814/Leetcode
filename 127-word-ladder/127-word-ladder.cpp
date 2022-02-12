class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s, visited;
        for(auto word:wordList){
            s.insert(word);
        }
        visited.insert(beginWord);
        if(!s.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        while(!q.empty()){
            int n = q.size();
            depth++;
            for(int i=0;i<n;i++){
                string str = q.front();
                q.pop();
                if(str==endWord) return depth;
                string temp="";
                for(int j=0;j<str.length();j++){
                       temp =str;
                    for(char k='a';k<='z';k++){
                        temp[j] = k;
                        if(s.count(temp) and !visited.count(temp)){
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
                
            }
        }
        return 0;
    }
};