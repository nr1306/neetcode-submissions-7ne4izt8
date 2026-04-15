class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int maxArea = 0;
        while(left < right){
            int width = right-left;
            int height = min(heights[right],heights[left]);
            maxArea = max(maxArea, height * width);
            if(height == heights[left])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};
