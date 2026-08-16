class Solution {
public:
    int findMin(vector<int> &nums) {
        int i=0, j = nums.size()-1;
        int minEle = INT_MAX;
        while(i<=j){
            int mid = (j-i)/2 + i;
            if(nums[i] <= nums[mid]){
                minEle = min(minEle, nums[i]);
                i=mid+1;
            }
            else{
                minEle = min(minEle, nums[mid]);
                j = mid;
            }
        }
        return minEle;
    }
};
