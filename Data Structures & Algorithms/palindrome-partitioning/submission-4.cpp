class Solution {
public:

    bool isPallindrome(string s, int i, int j){
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(string s, vector<vector<string>>& res, 
    vector<string> temp, int ind){
        if(ind == s.size()){
            res.push_back(temp);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            if(isPallindrome(s,ind,i)){
                temp.push_back(s.substr(ind, i-ind+1));
                solve(s,res,temp,i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        int n = s.size();
        solve(s,res,temp,0);

        return res;
    }
};
