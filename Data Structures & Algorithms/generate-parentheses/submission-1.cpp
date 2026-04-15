class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve("",0,0,n,res);
        return res;
    }

    void solve(string curr, int open, int close, int total, vector<string>& res){
        if(curr.size() == 2*total){
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
