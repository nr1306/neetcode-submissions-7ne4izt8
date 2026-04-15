class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, j=0;
        while(j<nums.size()){
            while(j<nums.size() && nums[j] == nums[i-1]) j++;
            // We are going to iterate through duplicate elements and will stop when find different element
            if(j<nums.size()){
                nums[i] = nums[j];
                i++;
            }
        }
        nums.resize(i);
        return i;
    }
};