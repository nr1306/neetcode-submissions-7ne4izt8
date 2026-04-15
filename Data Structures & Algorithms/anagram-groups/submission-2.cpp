class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams;

        for(string s : strs){
            string temp = s;
            sort(s.begin(), s.end());
            anagrams[s].push_back(temp);
        }

        vector<vector<string>> res;
        for(auto itr : anagrams){
            res.push_back(itr.second);
        }
        return res;
    }
};
