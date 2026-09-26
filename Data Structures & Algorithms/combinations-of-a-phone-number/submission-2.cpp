class Solution {
public:
    void solve(string digits, int ind, map<char,string>& dials, 
    string temp, vector<string>& res){
        if(ind == digits.size()){
            res.push_back(temp);
            return;
        }

        for(char ch : dials[digits[ind]]){
            temp += ch;
            solve(digits, ind+1, dials,temp,res);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string temp;

        if(digits == "") return res;
        
        map<char,string> dials;
        dials['2'] = "abc";
        dials['3'] = "def";
        dials['4'] = "ghi";
        dials['5'] = "jkl";
        dials['6'] = "mno";
        dials['7'] = "pqrs";
        dials['8'] = "tuv";
        dials['9'] = "wxyz";
        

        solve(digits, 0, dials, temp, res);
        return res;
    }
};
