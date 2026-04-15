class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        int i = 0, j = n-1;   
        while(i<j){
            int width = j-i;
            int height = min(heights[i],heights[j]);
            if(height*width > maxi) maxi = height*width;
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return maxi;
    }
};
