class Solution {
public:
    void solve(vector<string>& res, string str, string s, 
    unordered_set<string>& dict, int start, int i){
        if(i == s.size()-1){
            string temp = s.substr(start, i-start+1);
            if(dict.count(temp)){
                str += temp;
                res.push_back(str); // will insert if str is not ""
            }
            
            return;
        }

        string temp = s.substr(start, i-start+1);

        if(dict.count(temp)){
            solve(res,str + temp + " ",s,dict,i+1,i+1);
        }
        solve(res,str,s,dict,start,i+1);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string str : wordDict){
            dict.insert(str);
        }

        string str = "";
        vector<string> res;

        solve(res,str,s,dict,0,0);
        return res;
    }
};