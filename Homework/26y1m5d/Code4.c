/*一个同时和多个人聊天的人通常被我们叫做海王。
小J虽然觉得小R对他讲的话都是没有意义的废话，但事实上小J自己也是一个海王，他也想把自己说的那些没什么用的话同时发给很多人。
“小R，今天编程的课后作业是什么呢？”
“大佬，今天编程的课后作业是什么呢？”
“小老弟，今天编程的课后作业是什么呢？”
……
小J觉得发给每个人之前都需要把里面的称呼进行替换是一件很麻烦的事情，何况有的时候一句话中可能有很多次称呼，
他想要你帮他开发一个“海王自动转发机”，能够帮他完成对一句话中指定称呼的替换。
小J每一次会告诉你一个字符串 c，这是他想要发出去的话，他保证里面只有大小写字母，同时由于语言表意的特殊目的，他希望能够区分大小写。
小J还会告诉你字符串中已有的称呼 x，和希望替换的称呼 y，希望你能够把字符串 c 中所有的子串 x 都替换为 y。
若需要替换称呼为anan，c 中字符串包含banananc，则只需要替换出现在第2-5个字符的第一个anan。

输入
共3行。
第1行为小J想要进行替换的原始字符串 c。
第2行为需要被替换的子串 x。
第3行为需要替换的字符串 y。

输出
共1行，输出1个字符串表示将 c 中所有子串 x 替换为 y 后的字符串。

样例1
输入
Ananareyoufreetomorrow
Anan
Wangwang

输出
Wangwangareyoufreetomorrow

样例2
输入
AnandoyouthinkthattalkingtoAnanaboutthingsrelatedtoananisenough
Anan
Wangwang

输出
WangwangdoyouthinkthattalkingtoWangwangaboutthingsrelatedtoananisenough

提示
对于 30% 的数据，c 的长度不超过1000个字符，x 的长度不超过10个字符，且 x 仅在 c 中出现1次，y 的长度不超过100个字符。
对于 60% 的数据，c 的长度不超过1000个字符，x 的长度不超过10个字符，y 的长度不超过100个字符。
对于 100% 的数据，c 的长度不超过10000个字符，x 的长度不超过10个字符，y 的长度不超过1000个字符。*/

/**
 * @brief 字符串替换 - "海王自动转发机"
 * 
 * 算法思路：
 * 1. 从左到右扫描字符串c
 * 2. 每次找到子串x，就进行替换操作
 * 3. 根据x和y的长度关系，分三种情况处理：
 *    - len_y < len_x: 需要向前移动后续字符（收缩）
 *    - len_y == len_x: 直接覆盖
 *    - len_y > len_x: 需要向后移动后续字符（扩展）
 * 
 * 注意事项：
 * - 替换后需要更新字符串长度和扫描位置
 * - 数组大小需要足够大以容纳扩展后的字符串
 * - 最坏情况：10000个字符，每个都替换成1000字符，需要很大空间
 * 
 * 时间复杂度：O(len_c * 出现次数 * max(len_x, len_y))
 * 空间复杂度：O(len_c * len_y)
 */

#include <stdio.h>
#include <string.h>

int main() {
    char c[99999], x[11], y[1001];
    scanf("%s", c);
    scanf("%s", x);
    scanf("%s", y);

    int len_c = strlen(c);
    int len_x = strlen(x);
    int len_y = strlen(y);

    // 遍历字符串c，查找并替换所有x
    for (int i = 0; i < len_c; i++) {
        // 检查当前位置是否匹配子串x
        if (strncmp(&c[i], x, len_x) == 0) {
            // 情况1：y比x短，需要收缩
            if (len_y < len_x) {
                // 先用y覆盖前len_y个字符
                for (int j = i; j < i + len_y; j++) {
                    c[j] = y[j - i];
                }
                // 将后续字符向前移动
                for (int j = i + len_y; j < len_c - (len_x - len_y); j++) {
                    c[j] = c[j + (len_x - len_y)];
                }
                len_c -= (len_x - len_y);  // 更新字符串长度
                i += len_y - 1;  // 跳过已替换部分（-1是因为循环会i++）
            }
            // 情况2：y和x长度相同，直接覆盖
            else if (len_y == len_x) {
                for (int j = 0; j < len_y; j++) {
                    c[i + j] = y[j];
                }
            }
            // 情况3：y比x长，需要扩展
            else {
                // 先将后续字符向后移动，腾出空间
                for (int j = len_c - 1; j >= i + len_x; j--) {
                    c[j + (len_y - len_x)] = c[j];
                }
                // 用y覆盖
                for (int j = 0; j < len_y; j++) {
                    c[i + j] = y[j];
                }
                len_c += (len_y - len_x);  // 更新字符串长度
                i += len_y - 1;  // 跳过已替换部分
            }
        }
    }

    c[len_c] = '\0';  // 添加字符串结束符
    printf("%s\n", c);
    return 0;
}

// 注：当对原数组进行扩展时，若将数组大小定为10001，极有可能导致扩展后数组越界，故将数组大小定为99999。
// （虽然题目中说c的长度不超过10000个字符，x的长度不超过10个字符，y的长度不超过1000个字符，但为了保险起见，还是定大一些）