//������ˮ��
//����һ��N���ڵ������Ҫ�������������ߣ������������Ϊ��ȫͼ��������ͼ��Ψһ��С��������Ȼ���������
//�����ӵıߵ�Ȩֵ�ܺ���С�Ƕ��١�
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 13000;

int fa[N],s[N]; //s[i]��¼i�����ڵ���ͨ���ж��ٸ��ڵ�
struct Edge{
	int a,b,w;
}edge[N];
int n,t;

bool cmp(Edge x,Edge y){
	return x.w < y.w;
}

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++) fa[i] = i,s[i] = 1; //��ʼ�����鼯
		for(int i=1;i<n;i++) cin >> edge[i].a >> edge[i].b >> edge[i].w; //����n-1����
		sort(edge+1,edge+n,cmp);
		long long res = 0;
		for(int i=1;i<n;i++){
			int a = find(edge[i].a), b = find(edge[i].b);
			if(a != b){
				//�ڲ��ƻ���С������������£���Ҫ���������ϵ������-1(��ȥԭ�б�)*(w+1)(Ϊ�˲��ƻ���ҪȨ��+1)
				res += (long long)(s[a]*s[b] -1) * (edge[i].w+1); 
				fa[a] = b;
				s[b] += s[a];
			}
		}
		cout << res << endl;
	}
	
	return 0;
}
