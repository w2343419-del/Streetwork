/*在基于Internet的程序中，我们常常需要判断一个IP字符串的合法性。合法的IPv4地址是这样的形式：A.B.C.D
其中A、B、C、D均为位于[0, 255]中的整数。为了简单起见，我们规定这四个整数中不会有前导零存在，如001这种情况。现在，请你来完成这个判断程序吧。

输入
输入由多行组成，每行是一个字符串，输入由End of file结束。字符串长度最大为30，且不含空格和不可见字符。

输出
对于每一个输入，单独输出一行。如果该字符串是合法的IP，输出YES，否则，输出NO

样例
输入
202.115.32.24
a.b.c.d
End of file

输出
YES
NO*/
#include <stdio.h>
#include <string.h>
int main() {
    char ip[31];
    
    while (scanf("%s", ip) != EOF) {
        if (strcmp(ip, "End") == 0) {
            break;
        }
        
        int nums[4] = {0, 0, 0, 0};
        int numc = 0;
        int dotc = 0;
        int valid = 1;
        
        for (int i = 0; ip[i] != '\0'; i++) {
            if (ip[i] == '.') {
                dotc++;
                numc++;
                if (numc > 3) {
                    valid = 0;
                    break;
                }
            } else if (ip[i] >= '0' && ip[i] <= '9') {
                nums[numc] = nums[numc] * 10 + (ip[i] - '0');
                if (nums[numc] > 255) {
                    valid = 0;
                    break;
                }
            } else {
                valid = 0;
                break;
            }
        }
        
        if (dotc != 3 || numc != 3) {
            valid = 0;
        }
        
        if (valid == 1) {
            int len = 0;
            int zeroc = 0;
            for (int i = 0; ip[i] != '\0'; i++) {
                if (ip[i] == '.') {
                    len = 0;
                } else {
                    if (len == 0 && ip[i] == '0' && ip[i+1] != '.' && ip[i+1] != '\0') {
                        zeroc = 1;
                        break;
                    }
                    len++;
                }
            }
            if (zeroc) {
                valid = 0;
            }
        }
        
        if (valid == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}
