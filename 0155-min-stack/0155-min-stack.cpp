class MinStack {
public:
    stack<long long> st;
    long long min;

    MinStack() { }

    void push(long long val) {  
        if(st.empty()) {
            min = val;
            st.push(val);
        } else {
            if(val > min) {
                st.push(val);
            } else {
                st.push(2 * val * 1LL - min);
                min = val;
            }
        }  
    }

    void pop() { 
        if(st.empty()) return;   
        long long x = st.top();
        st.pop();
        if(x < min) {
           min = 2 * min - x;
        } 
    }

    long long top() {
        if(st.empty()) return -1;
        long long x = st.top();
        return (x < min) ? min : x;
    }

    long long getMin() {
        return min;
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