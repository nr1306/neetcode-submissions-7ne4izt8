class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // will store the indexes of elements as we move forward
    // understand we are finding nse and pse elements to know how long we can compute the rectangle
    // Their locations will be the border of our rectangle of ith height rectangle

        int area = INT_MIN;

        for(int i=0; i<heights.size(); i++){
    // Following condition is saying that we found the nse for all the elements in the stack, 
    // And the element who is at second place in stack will be the pse for the top element
    // Now we have both nse and pse and we can compute the area
            while(!st.empty() && heights[i] < heights[st.top()]){
                int nse = i; // ith element is smaller so it will be nse for the top stack element
                int ele = heights[st.top()];
                st.pop();
                
                int pse = -1; // out of the arr list
                if(!st.empty()) pse = st.top(); // second element in the stack will become pse for top element of stack
                area = max(area, ele*(nse-pse-1));
            }
            st.push(i);
        }

        int nse = heights.size();
        while(!st.empty()){
            int ele = heights[st.top()];
            st.pop();
            int pse = -1; // This is necessary coz for the first element of array pse = -1, if we are initializing outside then it will be updated
            if(!st.empty()) pse = st.top();
            area = max(area, ele*(nse-pse-1));
        }

        return area;
    }
};
