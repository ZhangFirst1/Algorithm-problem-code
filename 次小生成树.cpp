//次小生成树
//1.求最小生成树，统计并标记每条边是树边还是非树边；同时建树
//2.预处理任意两点间的边权最大值dis[a][b]
//3.依次枚举所有非树边，求min(sum + w - dis[a][b])，满足w > dis[a][b](严格次小生成树)

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
int dist1[N][N]; //处理得出的最小值
int dist2[N][N]; //处理得出的次小值
int h[N],e[N*2],ne[N*2],w[N*2],idx=0;

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int father,int max1,int max2,int dist1[],int dist2[]){  //当前的最大边权和次大边权，更新的最大数组1，次大数组2
    dist1[u]=max1,dist2[u]=max2;

    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j!=father){ //避免搜父节点
            if(w[i]>max1) dfs(j,u,w[i],max1,dist1,dist2);
            else if(w[i]<max1&&w[i]>max2) dfs(j,u,max1,w[i],dist1,dist2);  //注意！这里被卡了很久，w[i]不仅要大于max2，还不能等于max1
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
    //dfs处理出树上任意两点的最大值与次大值（因为最大值可能与非树边的边权相等）
    for(int i=1;i<=n;i++) dfs(i,-1,-1e9,-1e9,dist1[i],dist2[i]); //dfs()预处理树上节点之间的最小值和次小值

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
