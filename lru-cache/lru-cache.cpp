class LRUCache {
public:
    
    class node{
        public : 
        int key;
        int val;
        node* prev;
        node* next;
        
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int csize; //cache size
    unordered_map<int, node*>mp; //map to store key and its corresponding address in linked list
    
    //Insert node to the next of head (most recently used)
    void insertNode(node* n){ 
        node* temp = head->next;
        n->next = temp;
        n->prev = head;
        head->next = n;
        temp->prev = n;
    }
    //Delete node
    void deleteNode(node* n){
        node* prevv = n->prev;
        node* nextt = n->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }
    LRUCache(int capacity) {
        csize = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        //if key is present in map
        if(mp.find(key) != mp.end()){
            node* keyNode = mp[key];
            int res = keyNode->val;
            //This key becomes most recently used, so delete this key from its position
            deleteNode(keyNode);
            //and insert it at the position of most recently used 
            insertNode(keyNode);
            //Update the address in map
            mp[key] = head->next;
            return res;  
        }
        //if key is not present in map
        else
            return -1;
    }
    
    void put(int key, int value) {
        //if key is already present in map
        if(mp.find(key) != mp.end()){
            node* keyNode = mp[key];
            mp.erase(key);
            deleteNode(keyNode);
        }
        //if cache is full
        if(mp.size() == csize){
            //delete least recently used node
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        //Insert this node at the position of most recently used 
        insertNode(new node(key,value));
        //Update the address in map
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */