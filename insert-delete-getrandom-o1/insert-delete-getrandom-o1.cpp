class RandomizedSet {
private:
    unordered_map<int, int> m;
    vector<int> v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val)) return false;
        m[val]=v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)) return false;
        int idx=m[val];
           m.erase(val);
        if(idx<v.size()-1){
            int last_val=v[v.size()-1];
            v[idx]=last_val;
            m[last_val]=idx;
        }
        v.pop_back();
        return true;
    }
    
    int getRandom() {
      return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */