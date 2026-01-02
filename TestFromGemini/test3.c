/*输入一段文本，统计其中出现次数最多的“特征数字串”。
特征数字串定义：长度至少为 3，数字串首尾数字相同，且不以 0 开始。
另外，不考虑数的一部分，即 abc1231abc 中的 1231 是一个单独的数。（数据可能超过 32 位）

输入
输入数据为一段文本，可能包含若干行，直到文件末尾为止。

输出
对于每一组输入数据，输出出现次数最多的特征数字串和它出现的次数。如果有多个，按数字从大到小输出，每个数占一行。如果没有，输出 None。

提示
本题虽然是找整数，但最好的方法是全部按字符串处理。*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char num[100];
    int count;
} NumStr;

int compareNum(const char *a, const char *b) {
    if (strlen(a) != strlen(b))
        return strlen(b) - strlen(a);
    return strcmp(b, a);
}

int main() {
    char str[100000];
    NumStr nums[10000];
    int numCount = 0;

    while (fgets(str, sizeof(str), stdin)) {
        int len = strlen(str);
        
        for (int i = 0; i < len; i++) {
            if (isdigit(str[i]) && str[i] != '0') {
                for (int j = i + 2; j < len; j++) {
                    if (!isdigit(str[j])) {
                        if (str[i] == str[j-1] && j - i >= 3) {
                            char temp[100];
                            strncpy(temp, str + i, j - i);
                            temp[j - i] = '\0';
                            
                            int found = -1;
                            for (int k = 0; k < numCount; k++) {
                                if (strcmp(nums[k].num, temp) == 0) {
                                    found = k;
                                    break;
                                }
                            }
                            
                            if (found >= 0)
                                nums[found].count++;
                            else {
                                strcpy(nums[numCount].num, temp);
                                nums[numCount].count = 1;
                                numCount++;
                            }
                        }
                        i = j - 1;
                        break;
                    }
                }
            }
        }
    }

    if (numCount == 0) {
        printf("None\n");
        return 0;
    }

    int maxCount = 0;
    for (int i = 0; i < numCount; i++)
        if (nums[i].count > maxCount)
            maxCount = nums[i].count;

    for (int i = 0; i < numCount; i++) {
        if (nums[i].count == maxCount) {
            printf("%s\n", nums[i].num);
        }
    }

    return 0;
}