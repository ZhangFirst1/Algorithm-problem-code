//SPFA�󸺻�
//https://www.acwing.com/problem/content/906/
//�󸺻����÷���������SPFA
//(1)ͳ��ÿ������Ӵ��������ĳ�������n�Σ�˵�����ڸ���
//(2)ͳ�Ƶ�ǰÿ��������·���������ı��������ĳ������·�������ڵ���n��˵�����ڸ���
//��ѧ�����������е����Ӵ�������2nʱ����Ϊͼ���кܴ���ܴ��ڸ���
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
                cnt[j] = cnt[t] + 1;//��t��j����һ����w[t][j]
                if (cnt[j] >= n) return true; //���ڸ���
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
            //�涴 �ص�t��ǰ  ʱ��time-t��
            // ���򸺱�
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, -c);
        }

        if (spfa()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
