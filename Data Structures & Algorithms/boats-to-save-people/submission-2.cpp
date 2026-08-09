class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int i=0, j = people.size()-1;
        int count = 0; // number of boats

        while(i <= j){
            int weight = people[j];
            j--;
            count++;

    // if we can fit lightest person also in that boat
            if(i<=j && people[i] <= limit - weight) i++;
        }

        return count;
    }
};