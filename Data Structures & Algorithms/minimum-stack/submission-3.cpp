class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int mini = INT_MAX;
        stack<int> temp = st;
        while(!temp.empty()){
            mini = min(mini, temp.top());
            temp.pop();
        }
        return mini;
    }
};
