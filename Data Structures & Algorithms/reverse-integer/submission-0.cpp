class Solution {
public:
    int reverse(int n) {
        // for positive n
        if(n == 0) return 0;

        int maxi = pow(2,31)-1;
        int lastDigit = maxi%10;
        int nums = maxi/10; // without the last digit

        if(n < 0){
            maxi = -pow(2,31);
            lastDigit = maxi%10;
            nums = maxi/10;
        }

        // Now we'll reverse the number till n-1 th place
        // THen we'll check before adding the last value if the value is going to overflow the 32 bit integer range or not 
        // Because our environment can't have value outside of 32 bit integer range

        int res = 0;
        while(n >= 10 || (n<0 && n<=-10)){
            res = res*10 + n%10;
            n /= 10;
        }
        cout << res << " " << n;
        if(res > 0 && (res > nums || (res == nums && n > lastDigit)))
            return 0;
        else if(res < 0 && (res < nums || (res == nums && n < lastDigit))) // This is for negative input integer
            return 0;
        
        return res*10 + n;
    }
};
