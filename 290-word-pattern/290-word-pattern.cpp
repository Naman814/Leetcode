class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m1;
        unordered_map<string,bool> m2;
        vector<string> v;
        string word;
        istringstream ss(s); 
        while (ss >> word){
            v.push_back(word);
        }
          if (pattern.size() != v.size())
            return false;
        
        for(int i=0;i<pattern.size(); i++){
                if(m1.find(pattern[i])==m1.end()){
                        if(m2.find(v[i])!=m2.end()){
                            return false;
                        }
                        else{
                            m1[pattern[i]]=v[i];
                             m2[v[i]]=true;
                        }
                }
                else{
                    
                    if(m1[pattern[i]]!=v[i]){
                        return false;
                    }
                }

        }
        return true;
        
    }
};