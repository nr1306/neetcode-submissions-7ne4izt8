class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        int n = nums.size();
        for(int k=0; k<n; k++){
            if(nums[k] == 0 && i<k){
                swap(nums[k], nums[i]);
                k--;
                i++;
            }
            else if(nums[k] == 2 && j>k){
                swap(nums[k], nums[j]);
                k--;
                j--;
            }
        }

    }
};