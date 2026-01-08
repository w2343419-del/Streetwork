/**
 * @brief 结构体和指针操作示例
 * 
 * 演示内容：
 * - 定义包裹结构体Package
 * - 使用typedef创建别名
 * - 通过指针访问结构体成员
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

// 包裹结构体定义
struct Package {
    int PkgID;           // 包裹ID
    char Receiver[20];   // 接收人
    int weight;          // 重量
};

typedef struct Package Package;

int main() {
    // 初始化包裹
    Package pkg = {1, "Unknown", 10};
    Package* ptr = &pkg;
    
    // 通过指针访问成员
    printf("PkgID: %d; Receiver: %s; weight: %d\n", 
           ptr->PkgID, ptr->Receiver, ptr->weight);
    
    return 0;
}
