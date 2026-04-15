class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first+second);
            }
            else if(tokens[i] == "-"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first-second);
            }
            else if(tokens[i] == "*"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first*second);
            }
            else if(tokens[i] == "/"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                if(second)
                    st.push(first/second);
            }
            else{
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};
