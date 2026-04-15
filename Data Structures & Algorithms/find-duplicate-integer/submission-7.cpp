class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

    // finding the first collission between first and second pointer
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast) break; 
        }

    // finding the second collision , which will be our duplicate number

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
