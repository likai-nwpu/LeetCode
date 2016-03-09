class Solution {
public:
    bool isValid(string s) {
        int *temp_space = new int[s.length()];
        int top = -1;
        temp_space[++top] = s[0];
        size_t i = 1;
        for(; i < s.length();) {
            if(temp_space[top] == '(' && s[i] == ')' ||
               temp_space[top] == '[' && s[i] == ']' ||
               temp_space[top] == '{' && s[i] == '}') {
                top--;
                i++;
            }
            else {
                temp_space[++top] = s[i];
                i++;
            }
        }
        if(i == s.length() && top == -1)
            return true;
        else return false;
    }
};