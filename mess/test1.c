#include <stdio.h>
#include <stdlib.h>

// 判断数组是否满足条件
// a: 输入数组
// n: 数组长度
// 返回: 1表示不满足条件，0表示满足条件
int judge(const int a[], int n) {
    // 特殊情况：只有一个元素时，检查是否非零
    if (n == 1) {
        return a[0] != 0;
    }

    // 计算数组元素和
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        // 检查是否有小于1的元素
        if (a[i] < 1) return 1;
        sum += a[i];
    }
    
    // 检查和是否等于 2*(n-1)
    if (sum != 2LL * (n - 1)) {
        return 1;
    }

    // 贪心检查：从左到右验证可用性
    int available = a[0];
    for (int i = 1; i < n; i++) {
        if (available <= 0) {
            return 1;
        }
        available--;
        available += a[i] - 1;
    }

    return 0;
}

int main() {
    int t;
    // 读取测试用例数
    if (scanf("%d", &t) != 1) {
        return 0;
    }
    
    // 处理每个测试用例
    for (int i = 0; i < t; i++) {
        int n;
        // 读取数组长度
        if (scanf("%d", &n) != 1) {
            return 0;
        }

        int a[n]; 

        // 读取数组元素
        for (int k = 0; k < n; k++) {
            if (scanf("%d", &a[k]) != 1) {
                return 0;
            }
        }

        // 判断数组是否满足条件
        int count = judge(a, n);

        // 输出结果
        if (count == 1) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    
    return 0;
}