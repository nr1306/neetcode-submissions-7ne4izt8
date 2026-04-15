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

    void solve(string curr, int open, int close, int total, 
    vector<string>& res){
        if(curr.size() == total){
            if(isValid(curr))
                res.push_back(curr);
            return;
        }

        if(open < total){
            solve(curr+'(', open+1, close, total, res);
        }

        if(close < open){
            solve(curr+')', open, close+1, total, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        int open = 0, close = 0, total = 2*n;
        solve(curr,open,close,total,res);
        return res;
    }
};
