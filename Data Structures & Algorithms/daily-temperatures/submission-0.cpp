class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> res (n,0);
        
        for(int i=0; i<n; i++){
            pair<int,int> curr = {temperatures[i], i};
            if(!st.empty()){
                pair<int,int> temp = st.top();
                while(!st.empty() && curr.first > temp.first){
                    st.pop();
                    res[temp.second] = curr.second-temp.second;
                    if(!st.empty())
                        temp = st.top(); // now checking the next top element
                }
            }
            st.push(curr);
        }
        return res;
    }
};
