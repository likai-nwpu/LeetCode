class Solution {
public:
    int reverse(int x) {
        int e = x;
        string s(12,'\0');
        int p = 0;
        while(true) {
            s[p++] = e % 10 + '0';
            e /= 10;
            if(e == 0)
                break;
        }
        e = 0;
        for(int i = 0; s[i] != '\0'; i++) {
            if((x > 0 && e - 0x7FFFFFFF / 10 > 0) ||(x < 0 && e + 0x7FFFFFFF / 10 < 0))
                return 0;
            e *= 10;
            e += s[i] - '0';
        }
        return e;
    }
};