class Solution {
public:
    int getSum(int a, int b) {
        int carry = (a&b) << 1;
        int XOR = a^b;

        while(carry){
            int temp = XOR;
            XOR ^= carry;
            carry = (temp & carry) << 1;
        }
        return XOR;
    }
};
