class Solution {
public:
    string convert(string s, int numRows) {
        string rst(s);
        for(int i = 0, p = 0; i < numRows; i++) {
            rst[p++] = s[i];
            if(numRows == 1)
                break;
            for(int j = 1;;j++) {
                if(i == 0){
                    if(j * (2 * numRows - 2) < s.length())
                        rst[p++] = s[j * (2 * (numRows - 1))];
                    else break;
                } else if (i == numRows - 1) {
                    if((j * 2 * (numRows - 1) + (numRows - 1)) < s.length())
                        rst[p++] = s[j * 2 * (numRows - 1) + (numRows - 1)];
                    else break;
                } else {
                    if(j * (2 * (numRows - 1)) - i < s.length())
                        rst[p++] = s[j * (2 * (numRows - 1)) - i];
                    else break;
                    if(j * (2 * (numRows - 1)) + i < s.length())
                        rst[p++] = s[j * (2 * (numRows - 1)) + i];
                    else break;
                }
            }
       //     cout << rst;
        }
        return rst;
    }
};