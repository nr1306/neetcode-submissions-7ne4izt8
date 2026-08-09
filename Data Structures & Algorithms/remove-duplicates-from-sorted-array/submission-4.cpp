class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        if(n == 1) return 1;
        
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                nums[k] = nums[i-1];
                k++;
            }
        }
        if(k == 0){
            nums[k] = nums.back();
            k++;
        } 

        else if(nums[k-1] != nums.back()){
            nums[k] = nums.back();
            k++;
        }
        
        return k;
    }
};