class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> v_nse = nse(heights);
        vector<int> v_pse = pse(heights);
        for(int x : v_nse)
            cout << x << " ";
        cout << endl;

        int n = heights.size(), maxi = 0;
        for(int i=0; i<n; i++){
            int area = heights[i] * (v_nse[i]-v_pse[i]-1);
            maxi = max(maxi, area);
        }
        return maxi;
    }

    vector<int> nse (vector<int> heights){
        stack<int> st;
        int n = heights.size();
        vector<int> v_nse(n);
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                st.push(i);
                v_nse[i] = n;
                continue;
            }
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty())
                v_nse[i] = st.top();
            else
                v_nse[i] = n; // it means this element has no next smaller element
            st.push(i);
        }
        return v_nse;
    }

    vector<int> pse (vector<int> heights){
        stack<int> st;
        int n = heights.size();
        vector<int> v_pse(n);
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(i);
                v_pse[i] = -1;
                continue;
            }
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty())
                v_pse[i] = st.top();
            else
                v_pse[i] = -1; // it means this element has no next smaller element
            st.push(i);
        }
        return v_pse;
    }
};
