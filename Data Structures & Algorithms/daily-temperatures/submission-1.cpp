class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res (temp.size(),0);
        int n = temp.size();
        stack<pair<int,int>> st;
        st.push({temp[0],0});

        for(int i=1; i<n; i++){
            while(!st.empty() && temp[i] > st.top().first){
                int ind = st.top().second;
                st.pop();
                res[ind] = i-ind;
            }
            st.push({temp[i], i});
        }
        return res;
    }
};
