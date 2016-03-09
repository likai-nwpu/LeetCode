class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int max_length = 0, length = 0;
        bool sign = false;
        char common_char;
        if(strs.size() == 1)
            return strs[0];
        if(strs.size() == 0)
            return "";
        while(true) {
            for(size_t i = 1; i < strs.size(); i++) {
                if(strs[0][length] != strs[i][length] || strs[i].length() <= length) {
                    sign = true;
                    break;
                }
            }
            if(sign)
                break;
            length++;
        }
        return strs[0].substr(0, length);
    }
};
