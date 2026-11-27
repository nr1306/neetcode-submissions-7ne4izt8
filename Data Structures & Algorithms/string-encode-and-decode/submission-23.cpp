class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0) return res;

        cout << strs[0];
        string concat = "";
        for(string str : strs){
            int len = str.size();
            res += to_string(len) + ",";
            concat.append(str);
        }

        // res.resize(res.size()-1); // removing last comma
        res.append("|" + concat);
        // cout << res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        if(s.size() == 0) return res;

        stringstream ss(s);
        string len;
        getline(ss,len,'|'); // got all the lengths
        
        string concat = s.substr(len.size()+1);
        // got concat strings

        ss.str(len);
        string str;

        int j=0; // index in concat string
        while(getline(ss, str, ',')){
            int size = stoi(str);
            if(!size){
                res.push_back("");
                continue;
            }
            
            res.push_back(concat.substr(j,size));
            j += size;
        }

        return res;
    }
};
