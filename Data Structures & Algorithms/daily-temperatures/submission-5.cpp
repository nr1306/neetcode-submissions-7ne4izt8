class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        int n = temp.size();
        vector<int> res(n,0);

        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push({temp[i],i});
                continue;
            }

            int curr = temp[i];

            while(!st.empty() && curr > st.top().first){
                pair<int,int> temp_ind = st.top();
                int ind = temp_ind.second;
                res[ind] = i-ind;
                st.pop();
            }
            st.push({curr,i});
        }
        return res;
    }
};
