class MyHashSet {

public:
     int hset[1000001];
   
    MyHashSet() {
       for(int i=0;i<1e6+1;i++){
           hset[i] = -1;
       }
    }
    
    void add(int key) {
        hset[key]=1;
    }
    
    void remove(int key) {
        if(hset[key]!=-1){
            hset[key]=-1;
        }
    }
    
    bool contains(int key) {
        return hset[key]==-1?false:true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */