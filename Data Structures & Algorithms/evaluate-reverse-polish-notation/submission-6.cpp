class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string ch : tokens){
            if(ch == "+"){ 
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                int res = a+b;
                st.push(to_string(res));
            }
            else if(ch == "-"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                int res = b-a;
                st.push(to_string(res));
            }
            else if(ch == "*"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                int res = a*b;
                st.push(to_string(res));
            }
            else if(ch == "/"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                int res = a!= 0 ? b/a : 0;
                st.push(to_string(res));
            }
            else st.push(ch);
        }
        return stoi(st.top());
    }
};
