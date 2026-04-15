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

        int res = 0;
        while(n >= 10 || (n<0 && n<=-10)){
            res = res*10 + n%10;
            n /= 10;
        }
        // maxi = 2^31-1 = 2147483647
        /*
            So we are gonna reverse the number till n-1th place
            for eg: we got after reversing res = 214748364 which is equal to maxi if we remove last digit
            So we are gonna also compare if till n-1th iteration if res > maxi/10 will return. 0
            If maxi/10 is equal to res then will check the last digit if it is less than maxi%10 will add it to res else will return 0
            Same will do for negative numbers
        */
        if(res > 0 && (res > nums || (res == nums && n > lastDigit)))
            return 0;
        else if(res < 0 && (res < nums || (res == nums && n < lastDigit))) // This is for negative input integer
            return 0;
        
        return res*10 + n;
    }
};
