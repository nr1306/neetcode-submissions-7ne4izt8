class MinStack {
private: stack<int> st;
int minele;
public:
    MinStack() {
        minele = INT_MAX;
    }
    
    void push(int val) {
        st.push(val);
        minele = min(minele,val);
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if(!st.empty() && minele == val && st.top() < minele){
            minele = st.top();
        }
        else{
            minele = INT_MAX;
            stack<int> temp;
            while(!st.empty()){
                temp.push(st.top());
                minele = min(minele, st.top());
                st.pop();
            }
            while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minele;        
    }
};
