class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // We are gonna try do it in single traversal
        // We'll keep track of pse in the stack
        // we'll compute nse while traversing

        // This will take O(N)
        stack<int> st;
        int maxi = INT_MIN;
        for(int i=0; i<heights.size(); i++){ 
    // We'll insert the elements in the stack till we are facing to greater element 
            while(!st.empty() && heights[i] < heights[st.top()]){
                int nse = i;
                int ele = heights[st.top()];
                st.pop();
                int pse = -1;
                if(!st.empty()) pse = st.top();
                maxi = max(maxi, ele*(nse-pse-1));
            }
            
            st.push(i);
        }
        // If there are still elements left in the stack their nse = n
        while(!st.empty()){
            int ele = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = heights.size();
            maxi = max(maxi, ele*(nse-pse-1));
        }

        // TC : O(2N)
        // SC : O(1)
        return maxi;
    }
};
