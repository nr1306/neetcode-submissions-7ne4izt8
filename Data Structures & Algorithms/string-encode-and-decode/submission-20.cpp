class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        string concat = "";
        for(string str : strs){
            res.append(to_string(str.size())+ ",");
            concat.append(str);
        }
        // 4,3,2|
        res.append("|");
        res.append(concat);
        // 4,3,|starres

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        stringstream ss(s);
        string len;
        getline(ss,len,'|');
        // len : 4,3,
        int concaatStringsSize = s.size()-len.size();
        string concat = s.substr(len.size()+1, concaatStringsSize);

        stringstream stream(len);
        string size;
        int i=0;
        while(getline(stream,size,',')){
            int length = stoi(size);
            res.push_back(concat.substr(i,length));
            i += length;
        }
        return res;
    }
};
