class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = -1, ele2 = -1;

        for(int i=0; i<nums.size(); i++){
            if(cnt1 == 0 && ele2 != nums[i]){
                ele1 = nums[i];
                cnt1 = 1;
            } 
            else if(cnt2 == 0 && ele1 != nums[i]){
                ele2 = nums[i];
                cnt2 = 1;
            } 
            else if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> res;
        // Manual check is required, whether these elements are result or not
        cnt1 = 0, cnt2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
        }
        if(cnt1 > nums.size()/3) res.push_back(ele1);
        if(cnt2 > nums.size()/3) res.push_back(ele2);
        return res;
    }
};