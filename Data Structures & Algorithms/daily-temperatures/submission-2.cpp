class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        vector<int> res(temp.size(),0);

        for(int i=0; i<temp.size(); i++){  
            if(st.empty()) st.push({temp[i], i});
            else if(temp[i] < st.top().first) st.push({temp[i],i});
            else{
                while(!st.empty() && temp[i] > st.top().first){
                    int ind = st.top().second;
                    res[ind] = i-ind;
                    st.pop();
                }
                st.push({temp[i],i});
            }  
        }
        return res;
    }
};
