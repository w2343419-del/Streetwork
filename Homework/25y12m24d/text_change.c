/*以键盘输入多行文字以EOF结束，将它写入到当前目录下面的“t1.txt”中保存。
使用记事本打开该文件观察是否成功写入*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
extern int errno;
int main() {
    FILE *fp;
    int ch;
    fp = fopen("t1.txt", "w");
    if (fp == NULL) {
        printf ("Error: %s\n", strerror(errno));
        return 1;
    } else {
        while ((ch = getchar()) != EOF) {
            fputc(ch, fp);
        }
    }
    fclose(fp);
    return 0;
}
