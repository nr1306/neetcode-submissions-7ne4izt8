class Solution {
public:

    bool isValid(string curr){
        stack<char> st;
        for(char ch : curr){
            if(ch == '(')
                st.push(ch);
            else
                st.pop();
        }
        return st.empty();
    }

    void solve(string curr, vector<string>& res, int total, int open, int close){
        if(open+close == total){
            if(isValid(curr))
                res.push_back(curr);
            return;
        }

        if(open < total){
            solve(curr+"(", res, total, open+1, close);
        }

        if(close < open){
            solve(curr+")", res, total, open, close+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        solve(curr, res, 2*n, 0, 0);
        return res;
    }
};
