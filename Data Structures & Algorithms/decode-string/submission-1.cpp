class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '['){ // will simply inert into stack
                string temp = "";
                temp+=ch;
                st.push(temp);
            }
            // we'll collect whole string and push it into stack
            else if(ch >= 'a' && ch <= 'z'){ 
                string str = "";
                while(i<s.size() && ch >= 'a' && ch <= 'z'){
                    str += ch;
                    i++;
                    ch = s[i];
                }
                st.push(str);
                i--;
            }
            // we'll collect whole repeat num and push it into stack
            else if(ch >= '0' && ch <= '9'){
                string num = "";
                while(i<s.size() && ch >= '0' && ch <= '9'){
                    num += ch;
                    i++;
                    ch = s[i];
                }
                st.push(num);
                i--;
            }
            else{
                string ans = ""; // we'll generate our interm res and push it to stack
                string str = ""; // until opening bracket occours we'll concat all the strings in the stack
                while(st.top() != "["){
                    str = st.top() + str;
                    st.pop();
                }
                st.pop(); // st.top() == "["
                string num = st.top();
                st.pop(); // st.top() == num
                int repeat = stoi(num);

                for(int i=0; i<repeat; i++){
                    ans += str;
                }
                st.push(ans); // we are gonna push our interm result in stack
            }
            // cout << st.top() << endl;
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};