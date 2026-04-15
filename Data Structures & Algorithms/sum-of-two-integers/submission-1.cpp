class Solution {
public:
    int getSum(int a, int b) {
        int sum = a^b;
        int carry = (a&b) << 1;

        while(carry){
            int temp = sum^carry;
            carry = (sum&carry) << 1; // temp is used to use the old value of sum
            sum = temp;
        }
        return sum;
    }
};
