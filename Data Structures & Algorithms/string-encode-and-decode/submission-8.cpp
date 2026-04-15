using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
    
        for(string s : strs){
            res.append(s + "|");
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        if(s.size() == 0) return res;
        stringstream ss(s);
        string temp="";

        while(getline(ss,temp,'|')){
            res.push_back(temp);
        }
        return res;
    }
};
