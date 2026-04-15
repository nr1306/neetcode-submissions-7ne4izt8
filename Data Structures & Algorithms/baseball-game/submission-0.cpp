class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> res;
        int prev1 = -1, prev2 = -1;
        for(string str : operations){
            if(str == "+"){
                int n = res.size();
                int a = res[n-1];
                int b = res[n-2];
                res.push_back(a+b);
            }
            else if(str == "D"){
                int a = res.back();
                res.push_back(2*a);
            }
            else if(str == "C") res.pop_back();
            else{
                res.push_back(stoi(str));
            }
        }

        int sum = 0;
        for(int x : res) sum += x;
        return sum;
    }
};