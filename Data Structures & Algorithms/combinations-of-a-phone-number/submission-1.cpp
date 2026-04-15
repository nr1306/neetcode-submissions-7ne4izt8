class Solution {
public:
    map<char,string> dials;

    void solve(string digits, int i, string curr, vector<string>& res){
        if(i == digits.size()){
            res.push_back(curr);
            return;
        }

        for(char ch : dials[digits[i]]){
            curr += ch;
            solve(digits, i+1, curr, res);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        dials['2'] = "abc";
        dials['3'] = "def";
        dials['4'] = "ghi";
        dials['5'] = "jkl";
        dials['6'] = "mno";
        dials['7'] = "pqrs";
        dials['8'] = "tuv";
        dials['9'] = "wxyz";

        vector<string> res;
        string curr = "";
        if(digits.size() == 0) return res;
        
        solve(digits, 0, curr, res);

        return res;

    }
};
