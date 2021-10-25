class MinStack {
    
private : 
    stack<long long> s;
    long long mini;
public:
    MinStack() {
        while(!s.empty()) s.pop();
        mini=INT_MAX;
    }
    
    void push(int value) {
        long long val = value; 
        if(s.empty()) {
            mini = val; 
            s.push(val); 
        }
        else {
            if(val < mini) {
                s.push(2 * val * 1LL - mini);
                mini = val; 
            }
            else {
                s.push(val); 
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;
        long long curr_top=s.top();
        s.pop();
        if(curr_top<mini){
            mini=2*(mini)-curr_top;    
            //  mini=min(mini ,2*(mini)-curr_top); -> using this line is giving wrong answer  dont know why
        }
         
    }
    
    int top(){
        if(s.empty()) return -1;
        long long val=s.top();
        if(val<mini){
            return mini;
        }
        return val;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */