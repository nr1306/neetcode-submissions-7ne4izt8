class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, -1);
        if(n >= 0) ans[0] = 0;
        if(n >= 1) ans[1] = 1;
        if(n >= 2) ans[2] = 1;

        for(int i=3; i<=n; i++){
            int temp = i;
            temp = temp & temp-1;
            if(ans[temp] != -1){
                ans[i] = ans[temp]+1;
            }else {
                int count = 0;
                while(ans[temp] == -1){
                    count++;
                    temp = temp & temp-1;
                }
                ans[i] = ans[temp] + count;
            }
            cout << ans[i] << endl;
        }
        return ans;
        
    }
};
