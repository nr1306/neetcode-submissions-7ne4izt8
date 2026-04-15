class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string s : tokens){
            if(s != "+" && s != "-" && s != "*" && s != "/")
                st.push(s);
            else{
                int x = stoi(st.top()); // first right side operand will pop
                st.pop();
                int y = stoi(st.top()); // then left operand will pop
                st.pop();

                if(s == "+")
                    st.push(to_string(y+x));
                else if(s == "-")
                    st.push(to_string(y-x));
                else if(s == "*")
                    st.push(to_string(y*x));
                else
                    st.push(to_string(y/x));
            }
        }
        return stoi(st.top());
    }
};
