class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int,int> ind;
        for(int i=0; i<nums.size(); i++){
            ind[nums[i]] = i+1;
        }

        int maxi = 1;
        for(int i=0; i<nums.size(); i++){
            int count = 1;
            int ele = nums[i];
            int currInd = i;
            while(ind[ele+1] ){
                ele+=1;
                currInd = ind[ele+1]-1;
                count++;
            
                maxi = max(maxi, count);
            }
            if(maxi == nums.size()) break;
        }
        return maxi;
    }
};
