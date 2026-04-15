class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        vector<int> res;
        while(start < end){
            int sum = numbers[start] + numbers[end];
            if(sum == target) {
                res.push_back(start+1);
                res.push_back(end+1);
                break;
            }
            else if(sum < target) start+=1;
            else end-=1;
        }
        return res;
    }
};
