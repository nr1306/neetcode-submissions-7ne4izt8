class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        for(int k=0; k<=j; k++){
            if(nums[k] == 0){
                swap(nums,i,k);
                i++;
            }
            else if(nums[k] == 2){
                swap(nums,j,k);
                j--;
                k--;
            }
        }
    }
};