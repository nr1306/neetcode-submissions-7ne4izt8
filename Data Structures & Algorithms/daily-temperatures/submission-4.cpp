class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st; // {temp , ind}
        int n = temp.size();
        vector<int> res(n,0);

        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push({temp[i] , i});
                continue;
            }

            while(!st.empty() && temp[i] > st.top().first){
                pair<int,int> combo = st.top();
                st.pop();
                int ind = combo.second;

                res[ind] = i-ind;
            }

            st.push({temp[i], i});
        }

        return res;
    }
};
