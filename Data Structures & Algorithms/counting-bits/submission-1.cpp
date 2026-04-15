class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,-1);
        res[0] = 0;
        res[1] = 1;
        res[2] = 1;
        res[3] = 2;

        for(int i=4; i<=n; i++){
            int num = i;
            int count = 0;
            while(num){
                if(res[num] != -1){
                    count += res[num];
                    break;
                }
                num = num&(num-1);
                count++;
            }
            res[i] = count;
        }
        return res;
    }
};
