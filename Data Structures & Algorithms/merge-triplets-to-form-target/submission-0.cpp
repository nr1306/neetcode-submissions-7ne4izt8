class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int valid = 0;
        bool target1 = false, target2 = false, target3 = false;

        for(vector<int> temp : triplets){
            if(temp[0] <= target[0] && temp[1] <= target[1] && 
            temp[2] <= target[2]){
                valid++;
                if(temp[0] == target[0]) target1 = true;
                if(temp[1] == target[1]) target2 = true; 
                if(temp[2] == target[2]) target3 = true;
            }
        }
        return (valid && target1 && target2 && target3);
    }
};
