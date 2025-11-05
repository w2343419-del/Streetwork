// 猜数字游戏
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    char play_again;
    
    do {
        srand(time(0));
        int n = rand() % 100;
        int num = 0;
        int a;
        
        printf("开始游戏，请输入数字：\n");
        
        while (1) {
            scanf("%d", &a);
            
            if (num == 9) {
                printf("游戏结束\n");
                break;
            }
            
            if (a == n) {
                printf("正确\n");
                printf("一共猜了%d步\n", num + 1);
                break;
            } else if (a > n) {
                printf("太大\n");
            } else {
                printf("太小\n");
            }
            num++;
        }
        
        printf("是否进行下一轮游戏？(y/n)\n");
        scanf(" %c", &play_again);
        
    } while (play_again == 'y' || play_again == 'Y');
    
    printf("退出游戏\n");
    return 0;
}