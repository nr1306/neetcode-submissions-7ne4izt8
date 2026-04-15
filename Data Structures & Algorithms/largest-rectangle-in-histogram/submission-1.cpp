class Solution {
public:
    vector<int> next_smaller_element(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> res(n,n);

        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                res[i] = st.top();
            }
            st.push(i);
        }

        return res;
    }

    vector<int> previous_smaller_element(vector<int>& heights){
        vector<int> res(heights.size(),-1);
        stack<int> st;
        int n = heights.size();

        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                res[i] = st.top();
            }
            st.push(i);
        }

        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = next_smaller_element(heights);
        vector<int> pse = previous_smaller_element(heights);

        int maxi = INT_MIN;
        for(int i=0; i<heights.size(); i++){ 
            int area = heights[i] * (nse[i]-pse[i]-1);
            maxi = max(maxi, area);
        }
        return maxi;
    }
};
