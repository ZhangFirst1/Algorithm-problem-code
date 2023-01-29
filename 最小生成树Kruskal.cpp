//��С������ Kruskal
/*�Ȱѱ߰���Ȩֵ����������̰�ĵ�˼������ѡȡȨֵ��С�ıߣ����������ӣ�
�����ֻ��������˱ߣ��ò��鼯���ж��Ƿ���ڻ��������ѣ�
ֱ���Ѿ�ʹ�õıߵ��������ܵ�����һ���ɡ�*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 200050;

struct edges{
	int u,v,w;
}edge[N];
int ans,cnt,n,m,fa[N];

bool cmp(edges a,edges b){
	return a.w < b.w;
}

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);	//·��ѹ��
}

void Kruskal(){
	sort(edge+1,edge+1+m,cmp); //���߰�Ȩֵ����
	
	for(int i=1;i<=m;i++){
		int headu = find(edge[i].u);
		int headv = find(edge[i].v);
		if(headu == headv) continue; //����������Ѿ���ͨ�������߲�����Ҫ
		ans += edge[i].w;
		fa[headu] = headv; 	//��headu��headv�ϲ�
		
		if(++cnt == n-1) break;
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=m;i++) cin >> edge[i].u >> edge[i].v >> edge[i].w;
	
	Kruskal();
	
	if(cnt == n - 1) cout << ans;
	else cout << "impossible";
	
	return 0;
}
