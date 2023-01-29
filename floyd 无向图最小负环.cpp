//����ͼ����С������
//https://www.acwing.com/problem/content/description/346/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n, m;
int d[N][N], g[N][N];  // d[i][j] �ǲ�������
int pos[N][N];  // pos������м��k
int path[N], cnt;  // path ��ǰ��С���ķ���, cnt������ĵ������

// �ݹ鴦���Ͻڵ�
void get_path(int i, int j) {
    if (pos[i][j] == 0) return;  // i��j�����·û�о��������ڵ�

    int k = pos[i][j];  // ����,i ~ k ~ j�Ļ�,�ݹ鴦�� i ~ k�Ĳ��ֺ�k ~ j�Ĳ���
    get_path(i, k);
    path[cnt ++] = k;  // k��Ž�ȥ
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
    // dp˼·, ����k�ǻ��ϵ�����, i ~ k ~ j(Floyd��˼��)
    for (int k = 1; k <= n; k ++) {

        // ����С��, 
        //���ٰ���������Ļ��������ĵ���������k
        for (int i = 1; i < k; i ++)  // ���ٰ��������㣬i��j��k���غ�
            for (int j = i + 1; j < k; j ++)  
            // ����������ͼ,
            // ij������ʵ�Ǹ���תͼһ���ĵ���
            // ֱ�Ӽ�֦, j��i + 1��ʼ�ͺ���
            // ������С��, ��¼һ��·��
                if ((long long)d[i][j] + g[j][k] + g[k][i] < res) {
                    // ע��,ÿ�����������ʱ��, 
                    // d[i][j]�������һ�ֵ���Floyd�ó��Ľ��
                    // d[i][j] : i ~ j �м侭��������k - 1����̾���(k�ǲ���·���ϵ�)
                    res = d[i][j] + g[j][k] + g[k][i];  
                    cnt = 0;
                    path[cnt ++] = k;  // �Ȱ�k�Ž�ȥ
                    path[cnt ++] = i;  // ��k�ߵ�i(k�̶���)
                    get_path(i ,j);  // �ݹ���i��j��·��
                    path[cnt ++] = j;  // j��k, k�̶�
                }

        // Floyd, ����һ������ij����k�����·��
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
