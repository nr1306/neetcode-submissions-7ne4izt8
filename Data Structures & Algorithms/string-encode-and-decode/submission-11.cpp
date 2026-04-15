#include<bits/stdc++.h>
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
    // First storing the sizes of strings with comma seperated
        for(string s : strs){
            res.append(to_string(s.size()) + ",");
        }
    // Adding a break between sizes and strings
        res.append("#");

    // Then appending all strings without any seperator in between
        for(string s : strs){
            res.append(s);
        }

        cout << res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        vector<int> sizes;
        
        int i=0;
        string curr = "";
        for(; i<s.size(); i++){
            if(s[i] == '#') break; // We have encountered a break 
            
            if(s[i] == ','){
                sizes.push_back(stoi(curr));
                curr = "";
            }
            else curr+=s[i]; // We can't use append here coz s[i] is a char
        }
        i++; // to skip the '#'
        
        for(int size : sizes){
            res.push_back(s.substr(i, size));
            i += size;
        }

        return res;
    }
};
