class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void sortColors(vector<int>& nums) {
        int count0 = count(nums.begin(), nums.end(), 0);
        int count2 = count(nums.begin(), nums.end(),2);

        for(int i=0; i<nums.size(); i++){
            if(i<count0) nums[i] = 0;
            else if(i < (nums.size()-count2)) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};