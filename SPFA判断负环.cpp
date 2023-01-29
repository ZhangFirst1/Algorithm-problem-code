//SPFA求负环
//https://www.acwing.com/problem/content/906/
//求负环常用方法，基于SPFA
//(1)统计每个点入队次数，如果某个点入队n次，说明存在负环
//(2)统计当前每个点的最短路中所包含的边数，如果某点的最短路边数大于等于n，说明存在负环
//玄学做法：当所有点的入队次数超过2n时，认为图中有很大可能存在负环
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 510, M = 5210;
int n, m1, m2;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
int cnt[N];
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}
bool spfa()
{
    memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);

    queue<int> q;
    for (int i = 1; i <= n; i ++ )
    {
        q.push(i);
        st[i] = true;
    }

    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;//从t到j多了一条边w[t][j]
                if (cnt[j] >= n) return true; //存在负环
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        cin >> n >> m1 >> m2;
        memset(h, -1, sizeof h);
        idx = 0;
        for (int i = 0; i < m1; i ++ )
        {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c), add(b, a, c);
        }
        for (int i = 0; i < m2; i ++ )
        {
            //虫洞 回到t秒前  时间time-t秒
            // 单向负边
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, -c);
        }

        if (spfa()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
