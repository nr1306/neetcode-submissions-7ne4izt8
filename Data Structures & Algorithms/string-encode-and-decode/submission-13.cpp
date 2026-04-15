class Solution {
public:
    // We are gonna concatanate string along with their length to encode
    string encode(vector<string>& strs) {
        string res = "";
        string len = "";
    // we are gonna concat all the strings first with # as a break then all the sizes of strings with comma seperated
        for(string str : strs){
            res += str;
            len += to_string(str.length())+",";
        }
        // We will append first the size and then strings
        // for example vector contains one element "#" , It will encode string as ##1, which will create confusion and in decoding we'll break initially when encounterd "#"
        res = len+"#"+res;
        cout << res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        vector<int> sizes;
        int i=0;
        string len = "";
        for(; i<s.size(); i++){
            char ch = s[i];
            if(ch == ','){
                sizes.push_back(stoi(len));
                len = "";
                continue;
            }
            if(ch == '#') break;
            len += ch;
        }
        i++; // avoiding #
        
        for(int size : sizes){
            res.push_back(s.substr(i,size));
            i+=size;
        }
        return res;
    }
};
