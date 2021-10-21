class RandomizedSet {
    private:
    unordered_set<int> s;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end()){
            return false;
        }
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val)!=s.end()){
            auto it=s.find(val);
                   s.erase(it);
                   return true;
           }
        
        return false;
    }
    
    int getRandom() {
        vector<int> v;
        for(auto x:s){
            v.push_back(x);
        }
         int RandIndex = rand() % s.size(); 
         return v[RandIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */