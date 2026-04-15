class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> sortedOrder;
        for(string str : strs){
            string temp = str;
            sort(str.begin(), str.end());
            sortedOrder[str].push_back(temp);
        }
        vector<vector<string>> ans;
        for(auto it : sortedOrder){
            ans.push_back(it.second);
        }
        return ans;
    }
};
