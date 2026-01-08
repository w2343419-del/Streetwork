/*有两个字符串S1,S2，请编程检测S2是否在S1中对称出现(S2正串一定要在S2反串前面)，并输出最大对称间隔。
例如：
S1 = fabcdhba, S2 = ab，其中，ab...ba称为S2在S1中对称出现了1次，S2正串为ab，S2反串为ba，对称间隔为3。
S1 = abcdhbaghba, S2=ab，其中，ab...ba..ba称为S2在S1中对称出现了2次，对称间隔为3和7。
如果S2对称出现多次，则输出最大间隔。
注意：如果S2和S2的反串有部分重叠，那么间隔是负数。

输入
输入两个字符串S1,S2，以空格分开，字符串内部没有空格。
S1长度不超过300，S2的长度不超过10。

输出
输出S2最大对称间隔。
如果没有对称出现的S2出现，则输出no。

样例
输入
abcdhba abcd

输出
no

输入
abcdhbaghba ab

输出
7*/

#include <stdio.h>
#include <string.h>
int main() {
    char S1[300], S2[10];
    scanf("%s %s", S1, S2);

    char S2_turn[10];
    strcpy(S2_turn, S2);
    for (int i = 0; i < strlen(S2); i++) {
        S2_turn[i] = S2[strlen(S2) - 1 - i];
    }
    S2_turn[strlen(S2)] = '\0';

    int max_distance = -2147483648;
    int found = 0;

    if (strcmp(S2, S2_turn) == 0) {
        printf("no\n");
        return 0;
    }

    for (int i = 0; i <= strlen(S1) - strlen(S2); i++) {
        if (strncmp(&S1[i], S2, strlen(S2)) == 0) {
            for (int j = strlen(S1) - strlen(S2_turn); j >= i + strlen(S2); j--) {
                if (strncmp(&S1[j], S2_turn, strlen(S2_turn)) == 0) {
                    int distance = j - i - strlen(S2);
                    if (distance > max_distance) {
                        max_distance = distance;
                        found = 1;
                    }
                    break;
                }
            }
        }
    }

    if (found == 0) {
        printf("no\n");
    } else {
        printf("%d\n", max_distance);
    }
    
    return 0;
}
