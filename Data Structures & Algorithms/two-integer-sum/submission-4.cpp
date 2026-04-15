class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    // Here we don't need the elements position to be messed up
    // we can't use binary search and sort the array
    // We will use HashMap here, in 3sum we can use 2 pointers other than loop pointer
        vector<int> res;
        map<int,int> ind;
        ind[nums[0]] = 0;
        for(int i=1; i<nums.size(); i++){
            if(ind.find(target-nums[i]) != ind.end()){
                int ind2 = ind[target-nums[i]];
                if(i!=ind2){
                    res.push_back(ind2);
                    res.push_back(i);
                    break;
                }
            }
            ind[nums[i]] = i;
        }
        return res;
    }
};
