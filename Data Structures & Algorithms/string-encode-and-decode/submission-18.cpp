class Solution {
public:

    string encode(vector<string>& strs) {
        string len = "";
        string res = "";

// we are appending length first coz we are using seperator # between lengths and concat strs
// if we keep concat strs first it will coz confusion to find the seperator in one go

        for(string str : strs){
            len.append(to_string(str.size())+",");
            res.append(str);
        }
        
        res = len + "#" + res;
        cout << res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
    
        stringstream ss(s);
        string str;
    
    // reach the seperator and find oout len of strings
        getline(ss, str, '#'); // For now this str will contain the first half of strings containing len of strings
        stringstream lens(str); // we'll iterate and find len of strings
        
    // instead of using getline (to avoid confusion as there can be # present in concat strs) to find concat strs , we found the size and fetch that substring

        int lenConcatStrs = s.size() - (str.size()); 
        string concatStrs = s.substr(str.size()+1, lenConcatStrs); // +1 coz of # we planted in between

        string length;
        int start = 0;
        while(getline(lens, length, ',')){
            int len = stoi(length);
            res.push_back(concatStrs.substr(start,len)); // str contains other half of our data - concatanated strings
            start += len;
        }
        
        return res;
    }
};
