class Solution {
public:
    int myAtoi(string str) {
        char c[100];
        int rst = 0;
        int negative = 1;

        for(int i = 0; (str[i] < '0' || str[i] > '9') && str[i] !='\0'; i++) {
            if((str[i] == '-' || str[i] == '+') && (str[i + 1] < '0' || str[i + 1] > '9'))
               return 0;
            if(str[i] != '-' && str[i] != '+' && str[i] != ' ')
                return 0;
            if(str[i] == '-')
                negative = -1;
        }
        int l = 0;
        for(l = 0; (str[l] < '0' || str[l] > '9') && str[l] !='\0'; l++);
        for(int i = l, j = 0; str[i] != '\0'; i++) {
            if(str[i] >= '0' && str[i] <='9'){
                c[j++] = str[i];
                if(negative == 1 && (rst - 0x7FFFFFFF / 10 > 0 || (rst - 0x7FFFFFFF / 10 == 0 && str[i] - '0' > 7)))
                    return 0x7FFFFFFF;
                if(negative == -1 && (rst - 0x7FFFFFFF / 10 > 0 || (rst - 0x7FFFFFFF / 10 == 0 && str[i] - '0' > 8)))
                   return 0x80000000;
                rst *= 10;
                rst +=str[i] - '0';
            } else break;
        }
        rst *= negative;
        return rst;
    }
};