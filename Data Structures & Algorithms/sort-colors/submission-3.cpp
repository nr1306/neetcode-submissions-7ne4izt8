class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void sortColors(vector<int>& nums) {
        int i=0, j=nums.size()-1;

        for(int k=0; k<nums.size(); k++){
            if(nums[k] == 0 && i<=k){
                if(k != i){
                    swap(nums[k], nums[i]);
                    k--; 
                }
                i++;
            }
            else if(nums[k] == 2 && j>=k){
                if(k!=j){
                    swap(nums[j], nums[k]);
                    k--;
                }
                j--;
            }
        }
    }
};