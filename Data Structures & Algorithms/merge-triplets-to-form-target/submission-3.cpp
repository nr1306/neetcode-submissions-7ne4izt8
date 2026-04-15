class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        set<vector<int>> s(triplets.begin() , triplets.end());
        if(s.find(target) != s.end()) return true;

        int n = triplets.size();
        int valid = 0; // we need to find the triplet whose values is smaller than our target triplet
        bool existA = false, existB = false, existC = false;
        for(int i=0; i<n; i++){
            if(triplets[i][0] <= target[0] && 
            triplets[i][1] <= target[1] &&
            triplets[i][2] <= target[2]){
                valid++;

                if(triplets[i][0] == target[0]) existA = true;
                if(triplets[i][1] == target[1]) existB = true;
                if(triplets[i][2] == target[2]) existC = true;
            }
// We are checking the existence of elements inside the condn 
// coz there might be the case, element from target triplet exist but its other partners are greater than target values 
// which means this triplet will noe be any use, and will not mark that triplet as valid or won't market that element existed
        }

        return valid && existA && existB && existC;
    }
};
