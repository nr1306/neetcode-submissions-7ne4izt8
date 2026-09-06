class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n+1);

        for(vector<int> people : trust){
            degree[people[1]]++;
            degree[people[0]]--;
        }

        for(int i=1; i<=n; i++){
            if(degree[i] == n-1) return i;
        }
        return -1;
    }
};