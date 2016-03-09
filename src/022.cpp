
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int *location = new int[2 * n], p = 2 * n -1;
        int map_char[2] = {'(', ')'};
        vector<string> s;
        string str(2 * n,'(');
        location[0] = 0;
        for(size_t i = 0; i < 2 * n; i++)
            location[i] = 0;
        s.push_back(str);
        while(true) {
            if(location[p] >= 1) {
                //回溯到前一个尚未填满的地方
                while(location[--p] >= 1 && p >=0);
                if(p < 0)
                    break;
                location[p]++;
                str[p] = map_char[location[p]];
                for(int i = p + 1; i < 2 * n; i++) {
                    location[i] = 0;
                    str[i] = map_char[location[i]];
                }
                s.push_back(str);
                p = 2 * n - 1;
            } else {
                location[p]++;
                str[p] = map_char[location[p]];
                s.push_back(str);
            }
        }
        vector<string> rst;
        int *m_stack = new int[2 * n], top;
        for(auto c : s) {
            top = -1;
            m_stack[++top] = c[2 * n - 1];
            for(int i = 2 * n - 2; i >= 0; i--) {
                if(c[i] == '(' && m_stack[top] == ')') {
                    top--;
                } else
                    m_stack[++top] = c[i];
            }
            if(top == -1)
                rst.push_back(c);
        }
        return rst;
    }
};