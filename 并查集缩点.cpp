//���鼯����
//https://www.acwing.com/problem/content/1144/
//1.�����б�ѡ�߼��벢�鼯��
//2.�����зǱ�ѡ�ߴ�С��������
//3.��С����ö�ٷǱ�ѡ�ߣ�a��b��w
//	���a��b�Ѿ���ͨ ֱ��pass
//	������ͨ������ǰ��ѡ��
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 10010;
int fa[N];
struct Edge{
	int a,b,w;
	bool operator< (const Edge &t) const{
		return w < t.w;
	}
}edge[N];
int n,m;

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) fa[i] = i;
	
	int res = 0, cnt = 0;
	for(int i=1;i<=m;i++){
		int t,a,b,w;
		cin >> t >> a >> b >> w;
		if(t == 1){
			res += w;
			fa[find(a)] = find(b);
		}else{
			edge[++cnt] = {a,b,w};
		}	
	}
		
	sort(edge+1,edge+1+cnt);
	
	for(int i=1;i<=cnt;i++){
		int a = find(edge[i].a), b = find(edge[i].b);
		if(a != b){
			res += edge[i].w;
			fa[a] = b;
		}
	}
	
	cout << res;
	return 0;
}
