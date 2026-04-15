class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = INT_MIN;
        for(int i=0; i<heights.size(); i++){
            
            while(!st.empty() && heights[i] < heights[st.top()]){
                int nse = i;
                int pse = -1;
                int ele = heights[st.top()];
                st.pop();
                if(!st.empty()) pse = st.top();

                maxi = max(maxi, ele*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = heights.size();
            int pse = -1;
            int ele = heights[st.top()];
            st.pop();
            if(!st.empty()) pse = st.top();

            maxi = max(maxi, ele*(nse-pse-1));
        } 

        return maxi;
    }
};
