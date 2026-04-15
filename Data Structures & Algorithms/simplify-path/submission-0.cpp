class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string str = "";
        bool prevDir = false;
        getline(ss,str,'/');

        while(getline(ss,str,'/')){
            cout << str << endl;
            if(str == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(str == "." || str == "")
                continue;
            else st.push(str);
        }
        
        if(st.empty()) return "/";
        
        string res = "";
        while(!st.empty()){
            res = "/"+st.top() + res;
            st.pop();
        }
        return res;
    }
};