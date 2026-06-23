class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        
        for(int i=0, j=0; j<nums.size(); j++){
            if(s.find(nums[j]) == s.end()){
                s.insert(nums[j]);
                nums[i] = nums[j];
                i++;
            }
        }

        return s.size();
    }
};