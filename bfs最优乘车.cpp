//���ų˳�
//https://www.acwing.com/problem/content/description/922/
//���⽨ͼ+bfs+��������
#include <iostream>
#include <cstring>
#include <sstream>
#include <queue>

using namespace std;

const int N =510;

int m,n;
bool g[N][N]; // ���ڽӾ�������
int dist[N];
int stop[N];

void bfs()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    queue<int> q;
    q.push(1);

    while(q.size())
    {
        int t=q.front();
        q.pop();

        for(int i=1;i<=n;i++)
            if(g[t][i] && dist[i] > dist[t] +1)
            {
                dist[i]=dist[t] + 1;
                q.push(i);
            }
    }
}

int main()
{
    cin>>m>>n;

    string line;
    getline(cin,line); // ����س�

    while(m--)
    {
        getline(cin,line); // ����һ�в�֪�����ٸ�����ʱ�������stringstream
        stringstream ssin(line);  // ��string line ��ʼ�� stringstream ssin
        int cnt=0,p;
        while(ssin>>p) stop[cnt ++ ]=p;
        for(int j=0;j<cnt;j++)
            for(int k=j+1;k<cnt;k++)
                g[stop[j]][stop[k]]=true;
    }

    bfs();

    if(dist[n] == 0x3f3f3f3f) puts("NO");
    else cout<< max(dist[n]-1,0)<<endl;

    return 0;
}
