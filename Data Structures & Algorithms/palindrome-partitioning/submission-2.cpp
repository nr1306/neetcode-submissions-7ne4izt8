class Solution {
public:
    bool isValidPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void f(string s, set<vector<string>>& res, vector<string> temp,
    int index){
        if(index == s.size()){
            res.insert(temp);
            return;
        }

    // Everytime we are checking substr from index to n-1
    // While doing that we have already check [0-index] substr
        for(int i=index; i<s.size(); i++){
            if(isValidPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                // Now we have already checked substr till index i 
                f(s,res,temp,i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        set<vector<string>> res;
        vector<string> temp;
        f(s,res,temp,0);
        vector<vector<string>> ans(res.begin(), res.end());
        return ans;
    }
};
