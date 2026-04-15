class Solution {
public:
    
    void f(string& digits, int i, string temp, vector<string>& res,
    map<char,string>& dials){
        if(i == digits.size()){
            res.push_back(temp);
            return;
        }

        string dial = dials[digits[i]];
        for(int j=0; j<dial.size(); j++){
            temp += dial[j];
            // cout << to_string(dial[j]) << " ";
            f(digits,i+1,temp,res,dials);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0)
            return res;
        map<char,string> dials;
        dials['2'] = "abc";
        dials['3'] = "def";
        dials['4'] = "ghi";
        dials['5'] = "jkl";
        dials['6'] = "mno";
        dials['7'] = "pqrs";
        dials['8'] = "tuv";
        dials['9'] = "wxyz";
        string temp;
        f(digits,0,temp,res,dials);
        return res;
    }
};
