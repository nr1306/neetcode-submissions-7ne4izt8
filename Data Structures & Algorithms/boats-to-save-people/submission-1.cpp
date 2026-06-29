class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int i=0, j=people.size()-1;
        int boats = 0;

        while(i<=j){
            if(i == j){
                boats++;
                break;
            }
            int sum = people[i] + people[j];
            if(sum <= limit){
                i++;
                j--;
            }
            else{
                j--;
            }
            boats++;
        }

        return boats;
    }
};