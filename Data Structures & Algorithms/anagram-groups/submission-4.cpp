class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for(string str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            anagrams[temp].push_back(str);
        }

        vector<vector<string>> res;
        for(auto& [key,val] : anagrams){
            res.push_back(val);
        }

        return res;
    }
};
