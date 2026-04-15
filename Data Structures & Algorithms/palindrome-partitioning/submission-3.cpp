class Solution {
public:
    bool isValidPallindrome(string s, int i, int j){
        while(i<=j && s[i] == s[j]){
            i++;
            j--;
        }
        return i>j;
    }

    void solve(string s, int index, vector<string> temp, set<vector<string>>& res){
        if(index == s.size()){
            res.insert(temp);
            return;
        }

        for(int i=index; i<s.size(); i++){
            if(isValidPallindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                solve(s,i+1, temp, res);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        set<vector<string>> res;
        vector<string> temp;
        solve(s,0,temp,res);
        return vector<vector<string>>(res.begin(), res.end());
    }
};
