/*在某场赛事中，有 n 支队伍进行循环赛，即任意两支队之间都要进行一场比赛。
名次在 n/2 (含) 以内的队伍可以获奖。
名次按照积分和净得分从 1 开始依次往后排。
积分多的队伍名次靠前，如果积分相同，则净得分多的名次靠前，如果净得分仍然相同，则名次相同。
如果某个名次有多支队伍(例如 x 支)，则将跳过后续的 x−1 个名次再继续排名。

积分规则为：获胜一场积3分，平局积1分，输不积分。净得分为总得分-总失分。

输入

第一行一个整数 n (2≤n≤1000,n为偶数)，表示队伍数量；
随后 n 行，每行表示一支队伍的名称(队名包含字母数字和空格这几种字符，长度不超过50个字符)；
再随后 n(n−1)/2 行，每行的格式为 name1-name2: score1-score2 表示两队比赛得分。其中在:,-前后可能存在若干空格。每场得分不超过 100 分。

输出
按名次从前到后输出获奖队伍的名称。名次相同的队伍，按队名字典序顺序输出。

样例

输入
4
Team1
Team2
Team3
Team4
Team1-Team2:2-0
Team1-Team3:3-1
Team1-Team4:4-2
Team2-Team3:3-2
Team2-Team4:2-0
Team3-Team4:3-1

输出
Team1
Team2*/

#include <stdio.h>
#include <string.h>

struct team {
    char name[50];
    int points;
    int net_score;
};

int main() {
    int n;
    scanf("%d", &n);
    
    struct team teams[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%s", teams[i].name);
        teams[i].points = 0;
        teams[i].net_score = 0;
    }
    
    int matches = n * (n - 1) / 2;
    
    char name1[50], name2[50];
    int score1, score2;
    
    for (int i = 0; i < matches; i++) {
        scanf("%s-%s: %d-%d", name1, name2, &score1, &score2);
        
        if (score1 > score2) {
            teams[i].points += 3;
        } else if (score1 == score2) {
            teams[i].points += 1;
        } else {
            teams[i].points += 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        teams[i].net_score = teams[i].points - score1;
    }

    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            printf("%s\n", teams[i].name);
        }
        for (int i = n - 1; i >= n / 2; i--) {
            printf("%s\n", teams[i].name);
        }
    }
    

    return 0;
}