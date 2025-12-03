#include <stdio.h>

int MAX = 3;

int main() {
    //定义一个整数数组
    int var[] = {10, 100, 200};
    //定义一个整数变量 i 和一个整数指针 ptr
    int i, *ptr;
    
    //将 ptr 指向数组 var 的起始地址
    ptr = var;
    
    //循环遍历数组
    for (i = 0; i < MAX; i++) {
        //打印当前指针 ptr 所指向的地址
        printf("存储地址： var[%d] = %p\n", i, ptr);
        //打印当前指针 ptr 所指向地址的值
        printf("存储值： var[%d] = %d\n", i, *ptr);
        
        // 将指针 ptr 移动到下一个数组元素的位置
        ptr++;
    }
    return 0;
}