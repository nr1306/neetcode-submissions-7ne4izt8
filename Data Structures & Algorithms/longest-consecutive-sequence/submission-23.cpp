class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        map<int,int> ind;
        for(int i=0; i<nums.size(); i++)
            ind[nums[i]] = i+1;
        
        int maxi = 1;
        int count = 1;
        int prev = ind.begin()->first; 

        for(auto itr = ind.begin(); itr != ind.end(); itr++){
            int ele = itr->first;
            if(ele == prev) continue; // to avoid the first ele

            if(prev + 1 == ele) count++;
            else count = 1;
            
            prev = ele;
            maxi = max(maxi, count);
        }

        return maxi;
    }
};
