class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = INT_MIN;
        int l = 0, r = heights.size()-1;
        while(l<r){
            int h = min(heights[l], heights[r]);
            int w = r-l;

            area = max(area, h*w);

            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return area;
    }
};
