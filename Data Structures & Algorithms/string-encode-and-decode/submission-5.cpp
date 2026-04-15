class Solution {
public:

    string encode(vector<string>& strs) {
        if(!strs.size())
            return "";
        string res = "";
        for(string str : strs){
            res += str + "|";
        }
        // if(!res.size())
        //     res = ",";
        return res;
    }

    vector<string> decode(string s) {
        if(!s.size())
            return vector<string> {};
        if(s.size() == 1)
            return vector<string> {""};
        s.resize(s.size()-1);
        vector<string> ans;
        string word;
        stringstream ss(s);
        while(getline(ss, word, '|')){
            ans.push_back(word);
        }
        return ans;
    }
};
