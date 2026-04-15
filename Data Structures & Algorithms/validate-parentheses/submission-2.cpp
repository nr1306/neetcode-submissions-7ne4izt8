class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else{
                char Top;
                if(!st.empty()){
                    Top = st.top();
                    st.pop();
                }
                else return false;

                if((Top == '(' && ch == ')') || 
                (Top == '{' && ch == '}') || 
                (Top == '[' && ch == ']')) continue;
                else return false;
            }
        }
        return st.empty();
    }
};
