class Solution {
public:
    int maxArea(vector<int>& heights) {
        // For max area will start with 2 pointers farthest from each other to get max width coz area = height * width

        int i=0, j = heights.size()-1;
        int maxArea = 0;
        while(i < j){
            int h = min(heights[i], heights[j]);
            int w = j-i;
            maxArea = max(maxArea , h*w);

            if(heights[i] <= heights[j]) i++;
            else j--;
        }

        return maxArea;
    }
};
