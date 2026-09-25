class Solution {
public:
    bool isValid(string& curr){
        stack<char> st;

        for(char ch : curr){
            if(ch == '(') st.push(ch);
            else st.pop();
        }
        return st.empty();
    }

    void solve(vector<string>& res, string curr, int total, 
    int open, int close){

        if(open + close == total){
            if(isValid(curr)){
                res.push_back(curr);
            }
            return;
        }

        if(open < total){
            solve(res, curr+"(", total, open+1, close);
        }

        if(close < open)
            solve(res, curr+")", total, open, close+1);
        
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        int total = 2*n;
        solve(res,curr,total,0,0);
        return res;
    }
};
