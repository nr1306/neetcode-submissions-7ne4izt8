class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        stack<int> st;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else if(!st.empty() && st.top() == '(' && ch == ')'){
                st.pop();
                continue;
            } 
            else if(!st.empty() && st.top() == '[' && ch == ']'){
                st.pop();
                continue;
            }
            else if(!st.empty() && st.top() == '{' && ch == '}'){
                st.pop();
                continue;
            }
            else return false;
        }
        return st.empty();
    }
};
