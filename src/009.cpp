class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0)
        return false;
    int b = 1, temp = x;
    while(temp >= 10) {
        temp /= 10;
        b *= 10;
    }
    temp = x;
    int p = 1;
    while(b > p) {
        if((temp / b) % 10 != (temp % (p * 10)) / p)
            return false;
        b /= 10;
        p *= 10;
    }
    return true;
    }
};