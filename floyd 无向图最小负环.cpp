//无向图的最小环问题
//https://www.acwing.com/problem/content/description/346/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n, m;
int d[N][N], g[N][N];  // d[i][j] 是不经过点
int pos[N][N];  // pos存的是中间点k
int path[N], cnt;  // path 当前最小环的方案, cnt环里面的点的数量

// 递归处理环上节点
void get_path(int i, int j) {
    if (pos[i][j] == 0) return;  // i到j的最短路没有经过其他节点

    int k = pos[i][j];  // 否则,i ~ k ~ j的话,递归处理 i ~ k的部分和k ~ j的部分
    get_path(i, k);
    path[cnt ++] = k;  // k点放进去
    get_path(k, j);
}

int main() {
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i ++) g[i][i] = 0;

    while (m --) {	
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int res = INF;
    memcpy(d, g, sizeof g);
    // dp思路, 假设k是环上的最大点, i ~ k ~ j(Floyd的思想)
    for (int k = 1; k <= n; k ++) {

        // 求最小环, 
        //至少包含三个点的环所经过的点的最大编号是k
        for (int i = 1; i < k; i ++)  // 至少包含三个点，i，j，k不重合
            for (int j = i + 1; j < k; j ++)  
            // 由于是无向图,
            // ij调换其实是跟翻转图一样的道理
            // 直接剪枝, j从i + 1开始就好了
            // 更新最小环, 记录一下路径
                if ((long long)d[i][j] + g[j][k] + g[k][i] < res) {
                    // 注意,每当迭代到这的时候, 
                    // d[i][j]存的是上一轮迭代Floyd得出的结果
                    // d[i][j] : i ~ j 中间经过不超过k - 1的最短距离(k是不在路径上的)
                    res = d[i][j] + g[j][k] + g[k][i];  
                    cnt = 0;
                    path[cnt ++] = k;  // 先把k放进去
                    path[cnt ++] = i;  // 从k走到i(k固定的)
                    get_path(i ,j);  // 递归求i到j的路径
                    path[cnt ++] = j;  // j到k, k固定
                }

        // Floyd, 更新一下所有ij经过k的最短路径
        for (int i = 1; i <= n; i ++) 
            for (int j = 1; j <= n; j ++)   
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];  
                    pos[i][j] = k;
            }
    }

    if (res == INF) puts("No solution.");
    else {
        for (int i = 0; i < cnt; i ++) cout << path[i] << ' ';
        cout << endl;
    }

    return 0;
}
