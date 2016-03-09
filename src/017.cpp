class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> templ_all = {"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, templ, rst;
        if(digits.length() == 0)
            return rst;
        for(size_t i = 0; i < digits.length(); i++)
            templ.push_back(templ_all[digits[i] - '0']);
        int *location = new int[digits.length()], p = digits.length() - 1;
        string str(digits.length(),' ');
        for(size_t i = 0; i < digits.length(); i++)
            str[i] = templ[i][0];
        rst.push_back(str);
        location[0] = 0;
        for(size_t i = 0; i < digits.length(); i++)
            location[i] = 0;
        while(true) {
            if(location[p] >= templ[p].size() - 1) {
                //回溯到前一个尚未填满的地方
                while(--p >= 0 && location[p] >= templ[p].size() - 1);
                if(p < 0)
                    break;
                location[p]++;
                str[p] = templ[p][location[p]];
                for(int i = p + 1; i < digits.length(); i++) {
                    location[i] = 0;
                    str[i] = templ[i][location[i]];
                }
                rst.push_back(str);
                p = digits.length() - 1;
            } else {
                location[p]++;
                str[p] = templ[p][location[p]];
                rst.push_back(str);
            }
        }
        return rst;
    }
};