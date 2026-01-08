/*
 * 迷宫最短路径问题 - 使用深度优先搜索(DFS) + 回溯
 * 
 * 问题描述：
 * 给定一个m*n的地图，其中1表示可通行，0表示障碍
 * 找到从起点到终点的最短路径（最少步数）
 * 如果无法到达，输出-1
 * 
 * 算法思路：
 * 1. 从起点开始，尝试向四个方向（上下左右）移动
 * 2. 对于每个可行的位置，标记为已访问，递归搜索
 * 3. 到达终点时，记录步数并更新最小值
 * 4. 回溯时取消访问标记，以便探索其他路径
 * 5. 使用剪枝优化：当前步数 >= 已知最小步数时停止
 */

#include <stdio.h>

/* ==================== 常量定义 ==================== */
#define MAX_SIZE 51          // 地图最大尺寸
#define INF 999999999        // 无穷大（表示不可达）
#define WALKABLE 1           // 可通行标记
#define VISITED 1            // 已访问标记
#define NOT_VISITED 0        // 未访问标记
#define DIRECTION_COUNT 4    // 四个移动方向

/* ==================== 全局变量 ==================== */
// 地图尺寸
int rows, cols;              // 行数和列数

// 起点和终点
int start_x, start_y;        // 起点坐标
int target_x, target_y;      // 终点坐标

// 搜索相关
int min_steps = INF;         // 记录到达终点的最小步数

// 地图数据
int map[MAX_SIZE][MAX_SIZE];     // 地图：1表示可走，0表示障碍
int visited[MAX_SIZE][MAX_SIZE]; // 访问标记：1表示已访问，0表示未访问

// 方向数组（下、右、上、左）
int dir_x[DIRECTION_COUNT] = {1, 0, -1, 0};   // x方向偏移
int dir_y[DIRECTION_COUNT] = {0, 1, 0, -1};   // y方向偏移

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
 * 深度优先搜索 - 寻找最短路径
 * @param x 当前位置的行坐标
 * @param y 当前位置的列坐标
 * @param steps 从起点到当前位置的步数
 */
void dfs(int x, int y, int steps) {
    // 【终止条件1】到达目标点，更新最小步数
    if (x == target_x && y == target_y) {
        if (steps < min_steps) {
            min_steps = steps;
        }
        return;
    }

    // 【剪枝优化】如果当前步数已经 >= 已知最小步数，无需继续搜索
    if (steps >= min_steps) {
        return;
    }

    // 【核心搜索】尝试向四个方向移动
    for (int i = 0; i < DIRECTION_COUNT; i++) {
        // 计算新位置
        int next_x = x + dir_x[i];
        int next_y = y + dir_y[i];
        
        // 检查新位置是否可访问
        if (is_accessible(next_x, next_y)) {
            // 【标记】将新位置标记为已访问
            visited[next_x][next_y] = VISITED;
            
            // 【递归】继续向新位置搜索，步数+1
            dfs(next_x, next_y, steps + 1);
            
            // 【回溯】取消访问标记，以便探索其他路径
            // 这是回溯算法的关键：撤销当前选择，尝试其他可能
            visited[next_x][next_y] = NOT_VISITED;
        }
    }
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
    
    // 标记起点为已访问（防止重复访问起点）
    visited[start_x][start_y] = VISITED;
    
    // 从起点开始深度优先搜索，初始步数为0
    dfs(start_x, start_y, 0);
    
    // 输出结果
    if (min_steps == INF) {
        printf("-1\n");              // 无法到达终点
    } else {
        printf("%d\n", min_steps);   // 输出最小步数
    }

    return 0;
}