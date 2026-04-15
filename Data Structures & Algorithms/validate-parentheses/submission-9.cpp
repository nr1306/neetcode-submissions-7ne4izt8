class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 != 0) return false;
        stack<char> st;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()) return false; // if there is closing bracket before openeing bracket then its invalid
                char front = st.top();
                if(front == '(' && ch == ')') st.pop();
                else if(front == '{' && ch == '}') st.pop();
                else if(front == '[' && ch == ']') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};
