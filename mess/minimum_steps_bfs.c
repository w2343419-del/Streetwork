/*
 * 迷宫最短路径问题 - 使用广度优先搜索(BFS)
 * 
 * 问题描述：
 * 给定一个m*n的地图，其中1表示可通行，0表示障碍
 * 找到从起点到终点的最短路径（最少步数）
 * 如果无法到达，输出-1
 * 
 * 算法对比：
 * BFS vs DFS:
 * - BFS找到的第一条路径就是最短路径，无需遍历所有可能
 * - 时间复杂度：O(rows * cols) vs O(4^n)
 * - 空间复杂度：O(rows * cols) 需要队列
 * - 适用场景：无权图最短路径问题优先使用BFS
 * 
 * 算法思路：
 * 1. 使用队列存储待访问的位置
 * 2. 从起点开始，将其加入队列
 * 3. 每次取出队首元素，检查是否为终点
 * 4. 向四个方向扩展，将未访问的可行位置加入队列
 * 5. 第一次到达终点时，即为最短路径
 */

#include <stdio.h>

/* ==================== 常量定义 ==================== */
#define MAX_SIZE 51          // 地图最大尺寸
#define MAX_QUEUE 2600       // 队列最大容量 (51*51)
#define WALKABLE 1           // 可通行标记
#define VISITED 1            // 已访问标记
#define NOT_VISITED 0        // 未访问标记
#define DIRECTION_COUNT 4    // 四个移动方向

/* ==================== 数据结构 ==================== */

/**
 * 队列节点 - 存储位置和步数信息
 */
typedef struct {
    int x;        // 行坐标
    int y;        // 列坐标
    int steps;    // 从起点到当前位置的步数
} Node;

/**
 * 循环队列
 */
typedef struct {
    Node data[MAX_QUEUE];  // 队列数据
    int front;             // 队首指针
    int rear;              // 队尾指针
} Queue;

/* ==================== 全局变量 ==================== */
// 地图尺寸
int rows, cols;              // 行数和列数

// 起点和终点
int start_x, start_y;        // 起点坐标
int target_x, target_y;      // 终点坐标

// 地图数据
int map[MAX_SIZE][MAX_SIZE];     // 地图：1表示可走，0表示障碍
int visited[MAX_SIZE][MAX_SIZE]; // 访问标记：1表示已访问，0表示未访问

// 方向数组（下、右、上、左）
int dir_x[DIRECTION_COUNT] = {1, 0, -1, 0};   // x方向偏移
int dir_y[DIRECTION_COUNT] = {0, 1, 0, -1};   // y方向偏移

/* ==================== 队列操作 ==================== */

/**
 * 初始化队列
 * @param q 队列指针
 */
void init_queue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

/**
 * 判断队列是否为空
 * @param q 队列指针
 * @return 1表示空，0表示非空
 */
int is_empty(Queue *q) {
    return q->front == q->rear;
}

/**
 * 入队操作
 * @param q 队列指针
 * @param x 行坐标
 * @param y 列坐标
 * @param steps 步数
 */
void enqueue(Queue *q, int x, int y, int steps) {
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
    q->data[q->rear].steps = steps;
    q->rear = (q->rear + 1) % MAX_QUEUE;
}

/**
 * 出队操作
 * @param q 队列指针
 * @return 队首节点
 */
Node dequeue(Queue *q) {
    Node node = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE;
    return node;
}

/* ==================== 辅助函数 ==================== */

/**
 * 初始化visited数组
 */
void init_visited() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            visited[i][j] = NOT_VISITED;
        }
    }
}

/**
 * 判断位置是否在地图范围内
 * @param x 行坐标
 * @param y 列坐标
 * @return 1表示在范围内，0表示超出范围
 */
int is_in_bounds(int x, int y) {
    return x >= 1 && x <= rows && y >= 1 && y <= cols;
}

/**
 * 判断位置是否可以访问
 * @param x 行坐标
 * @param y 列坐标
 * @return 1表示可访问，0表示不可访问
 */
int is_accessible(int x, int y) {
    return is_in_bounds(x, y) && 
           map[x][y] == WALKABLE && 
           visited[x][y] == NOT_VISITED;
}

/* ==================== 核心算法 ==================== */

/**
 * 广度优先搜索 - 寻找最短路径
 * @return 最短路径的步数，如果无法到达返回-1
 */
int bfs() {
    Queue q;
    init_queue(&q);
    
    // 【初始化】将起点加入队列
    enqueue(&q, start_x, start_y, 0);
    visited[start_x][start_y] = VISITED;
    
    // 【BFS主循环】当队列不为空时继续搜索
    while (!is_empty(&q)) {
        // 取出队首节点
        Node current = dequeue(&q);
        
        // 【终止条件】到达目标点，返回步数
        // BFS保证第一次到达就是最短路径
        if (current.x == target_x && current.y == target_y) {
            return current.steps;
        }
        
        // 【扩展】尝试向四个方向移动
        for (int i = 0; i < DIRECTION_COUNT; i++) {
            int next_x = current.x + dir_x[i];
            int next_y = current.y + dir_y[i];
            
            // 检查新位置是否可访问
            if (is_accessible(next_x, next_y)) {
                // 标记为已访问（BFS不需要回溯，标记后不再修改）
                visited[next_x][next_y] = VISITED;
                
                // 将新位置加入队列，步数+1
                enqueue(&q, next_x, next_y, current.steps + 1);
            }
        }
    }
    
    // 队列为空仍未找到终点，说明无法到达
    return -1;
}

/* ==================== 主函数 ==================== */

int main() {
    // 输入地图大小
    scanf("%d%d", &rows, &cols);

    // 输入地图数据（1表示可走，0表示障碍）
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // 输入起点和终点坐标
    scanf("%d%d%d%d", &start_x, &start_y, &target_x, &target_y);
    
    // 初始化visited数组
    init_visited();
    
    // 【边界检查1】起点等于终点，直接返回0
    if (start_x == target_x && start_y == target_y) {
        printf("0\n");
        return 0;
    }
    
    // 【边界检查2】起点或终点是障碍，无法到达
    if (map[start_x][start_y] != WALKABLE || map[target_x][target_y] != WALKABLE) {
        printf("-1\n");
        return 0;
    }
    
    // 【边界检查3】起点或终点超出范围
    if (!is_in_bounds(start_x, start_y) || !is_in_bounds(target_x, target_y)) {
        printf("-1\n");
        return 0;
    }
    
    // 执行BFS搜索
    int result = bfs();
    
    // 输出结果
    printf("%d\n", result);

    return 0;
}
