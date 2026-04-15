class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() == 3){
            vector<vector<int>> res;
            if(nums[0] + nums[1] + nums[2] == 0){
                vector<int> temp;
                temp.push_back(nums[0]);
                temp.push_back(nums[1]);
                temp.push_back(nums[2]);
                res.push_back(temp);
            }
            return res;
        }

        sort(nums.begin(), nums.end());
        int target = 0;
        set<vector<int>> s;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){

                int left = j, right = nums.size()-1;
                while(left < right){
                    int sum = nums[i]+nums[left]+nums[right];
                    if(sum == target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        s.insert(temp);
                        break;
                    }
                    else if(sum < target) left++;
                    else right--;
                }
            }
        }
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};
