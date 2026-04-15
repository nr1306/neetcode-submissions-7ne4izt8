class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> freq;
        for(int i=0; i<nums.size(); i++){
            if(freq[target-nums[i]]){
                int smallerInd = min(i,freq[target-nums[i]]-1);
                int biggerInd = max(i,freq[target-nums[i]]-1);
                return vector<int> {smallerInd, biggerInd};
            }
            freq[nums[i]] = i+1;
        }
        return vector<int> {-1,-1};
    }
};
