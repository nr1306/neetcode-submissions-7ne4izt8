class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void check(string s, int index, 
    vector<string> str, vector<vector<string>>& res){
        if(index == s.size()){
            res.push_back(str);
            return;
        }

        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s,index,i)){
                str.push_back(s.substr(index, i-index+1));
                check(s,i+1,str,res);
                str.pop_back();
            }
        }

    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> str;
        check(s,0,str,res);
        return res;
    }
};
