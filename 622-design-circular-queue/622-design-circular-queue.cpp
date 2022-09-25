class MyCircularQueue {
public:
    vector<int> v;
    int f=0,r=0,n;
    MyCircularQueue(int k) {
        vector<int> temp(k+1);
        v = temp;
        n = k+1;
    }
    
    bool enQueue(int value) {
        if((r+1)%n==f) return false;
        r = (r+1)%n;
        v[r] = value;
        return true;
    }
    
    bool deQueue() {
        if(r==f) return false;
        f = (f+1)%n;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return v[(f+1)%n];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return v[r];
    }
    
    bool isEmpty() {
        return r==f ? true : false;
    }
    
    bool isFull() {
        return (r+1)%n == f ? true:false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */