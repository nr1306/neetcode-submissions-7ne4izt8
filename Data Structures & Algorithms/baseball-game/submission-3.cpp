class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        long long score = 0;
        vector<int> prev;

        for(int i=0; i<n; i++){
            string str = operations[i];
            if(str == "+"){
                // operation
                int sum = prev[prev.size()-2] + prev.back();

                prev.push_back(sum);
                
                // adding it to score
                score += sum;
            }
            else if(str == "D"){
                // operation
                int temp = 2*prev.back();

                // keeping only 2 num
                prev.push_back(temp);

                // adding it to score
                score += temp;
            }
            else if(str == "C"){
                // removing last number
                score -= prev.back();

                prev.pop_back();
            }
            else{
                int num = stoi(operations[i]);
                prev.push_back(num);

                // adding it to score
                score += num;
            }
        }

        return score;
    }
};