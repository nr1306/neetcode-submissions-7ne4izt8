class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = -1,ele2 = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(cnt1 == 0 && ele2 != nums[i]){
                ele1 = nums[i];
                cnt1=1;
            }
            else if(cnt2 == 0 && ele1 != nums[i]){
                ele2 = nums[i];
                cnt2=1;
            }
            else if(ele1 == nums[i]) cnt1++;
            else if(ele2 == nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }

        vector<int> res;
        if(cnt1 > n/3) res.push_back(ele1);
        if(cnt2 > n/3 && ele1 != ele2) res.push_back(ele2);

        return res;
    }
};