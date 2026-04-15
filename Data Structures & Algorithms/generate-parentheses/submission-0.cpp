class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve("",0,0,2*n,res);
        return res;
    }

    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == '(')
                st.push(ch);
            else if(!st.empty() && st.top() == '(')
                st.pop();
            else
                return false;
        }
        return st.empty();
    }

    void solve(string curr, int open, int close, int total, vector<string>& res){
        if(curr.size() == total){
            if(isValid(curr))
                res.push_back(curr);
            return;
        }

        if(open < total){
            solve(curr+'(',open+1,close,total,res);
        }

        if(close < open){
            solve(curr+')',open,close+1,total,res);
        }
    }
};
