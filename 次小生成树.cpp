//��С������
//1.����С��������ͳ�Ʋ����ÿ���������߻��Ƿ����ߣ�ͬʱ����
//2.Ԥ�������������ı�Ȩ���ֵdis[a][b]
//3.����ö�����з����ߣ���min(sum + w - dis[a][b])������w > dis[a][b](�ϸ��С������)

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1010, M = 10010;
typedef long long LL;

struct Edge{
    int a,b,w;
    bool is_tree;
    bool operator < (const Edge &W){
        return w<W.w;
    }
}edge[M];
int n,m;
int fa[N];
int dist1[N][N]; //����ó�����Сֵ
int dist2[N][N]; //����ó��Ĵ�Сֵ
int h[N],e[N*2],ne[N*2],w[N*2],idx=0;

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int father,int max1,int max2,int dist1[],int dist2[]){  //��ǰ������Ȩ�ʹδ��Ȩ�����µ��������1���δ�����2
    dist1[u]=max1,dist2[u]=max2;

    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j!=father){ //�����Ѹ��ڵ�
            if(w[i]>max1) dfs(j,u,w[i],max1,dist1,dist2);
            else if(w[i]<max1&&w[i]>max2) dfs(j,u,max1,w[i],dist1,dist2);  //ע�⣡���ﱻ���˺ܾã�w[i]����Ҫ����max2�������ܵ���max1
            else dfs(j,u,max1,max2,dist1,dist2);
        }
    }
}

int main(){
    memset(h,-1,sizeof h);

    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].w);
    }

    sort(edge+1,edge+1+m);

    for(int i=1;i<=n;i++) fa[i]=i;

    LL sum=0;
    for(int i=1;i<=m;i++){
        int a=edge[i].a,b=edge[i].b,w=edge[i].w;
        int pa=find(a),pb=find(b);
        if(pa!=pb){
            fa[pa]=pb;
            sum+=w;
            edge[i].is_tree=true;
            add(a,b,w),add(b,a,w);
        }
    }
    //dfs���������������������ֵ��δ�ֵ����Ϊ���ֵ����������ߵı�Ȩ��ȣ�
    for(int i=1;i<=n;i++) dfs(i,-1,-1e9,-1e9,dist1[i],dist2[i]); //dfs()Ԥ�������Ͻڵ�֮�����Сֵ�ʹ�Сֵ

    LL res=1e18;
    for(int i=1;i<=m;i++){
        if(!edge[i].is_tree){
            int a=edge[i].a,b=edge[i].b,w=edge[i].w;
            if(w>dist1[a][b]){
                res=min(res,sum+w-dist1[a][b]);
            }
            else if(w>dist2[a][b]){
                res=min(res,sum+w-dist2[a][b]);
            }
        }
    }
    cout << res << endl;
    return 0;
}
