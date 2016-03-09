class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() == 0 && needle.length() == 0)
            return 0;
        int *next = new int[needle.length() + 1];
        next[0] = -1;
        for(int i = 0, j = -1; i < needle.length();) {
            while(needle[i] != needle[j] && j >=0)
                //µÝ¹éµÄÕÒÇ°×º
                j = next[j];
            next[++i] = ++j;
        }
        int i = 0, j = 0;
        while(i <= haystack.length()) {
            if(j >= needle.length())
                return i - j;
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            } else if(j == 0) {
                i++;
            } else {
                j = next[j];
            }
        }
        return -1;
    }
};