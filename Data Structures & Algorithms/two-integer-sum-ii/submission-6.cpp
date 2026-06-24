class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        mp[nums[0]] = 1; // storing the first index
        int n = nums.size();
        vector<int> res;
        for(int i=1; i<n; i++){
            if(mp.find(target-nums[i]) != mp.end()){
                int ind1 = mp[target-nums[i]]-1;
                int ind2 = i;

                if(ind1 != ind2){
                    res.push_back(ind1+1);
                    res.push_back(ind2+1);
                    break;
                }
            }

            mp[nums[i]] = i+1;
        }

        return res;
    }
};
