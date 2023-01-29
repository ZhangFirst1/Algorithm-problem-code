//�����������
//1.���ϱ�Ƿ�O(n)
//2.��������Ԥ����ÿ����������2^k���ĸ�����˭
//Ԥ����O(nlogn) ��ѯO(logn)
//fa[i][j]��ʾ��i��ʼ������2^j�������ߵ��Ľڵ�
//	j = 0, fa[i][j]Ϊi�ĸ��ڵ�
//	j > 0, fa[i][j] = fa[fa[i][j-1]] [j-1](������2^(j-1))
//depth[i]��ʾ���
//�ڱ��������i��ʼ��2^j�����������ڵ㣬��ôfa[i, j] = 0, depth[0] = 0
//(1)�Ƚ�����������ͬһ�㣺������ƴ�գ��Ӹ�λ����λ
//(2)��������ͬʱ��������һֱ������������������ȵ���һ��(�����ͬһ���жϿ��������ĵ㲻�������������)

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 40010, M = N*2;

int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][16]; //�40000���㣬2^16 > 40000

void add(int a,int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
//���ѳ�ʼ��depth��fa
void bfs(int root){
	memset(depth, 0x3f, sizeof depth);
	depth[0] = 0, depth[root] = 1;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		
		for(int i=h[t]; i != -1;i = ne[i]){
			int j = e[i];
			if(depth[j] > depth[t] + 1){
				depth[j] = depth[t] + 1;
				q.push(j);
				
				fa[j][0] = t; //������1��
				for(int k=1;k<=15;k++){
					fa[j][k] = fa[fa[j][k-1]][k-1]; //��������
				}
				
			}
		}	
	}
}

int lca(int a,int b){
	if(depth[a] < depth[b]) swap(a, b); //a��b���ϱ� ����һ�£������±ߵĵ㿪ʼ��
	
	for(int k=15;k>=0;k--)				//����ͬһ��
		if(depth[fa[a][k]] >= depth[b]) //��a��ʼ��2^k������b�±�
			a = fa[a][k];
	
	if(a == b) return a; //����Ѿ��ҵ������������
	
	for(int k=15;k>=0;k--)
		if(fa[a][k] != fa[b][k]) 	//û�������������ȵ���һ��
		{
			a = fa[a][k];
			b = fa[b][k];
		}
	return fa[a][0];			
}

int main(){
	cin >> n;
	int root = 0;
	memset(h, -1, sizeof h);
	for(int i=1;i<=n;i++){
		int a, b;
		scanf("%d%d",&a,&b);
		if(b == -1)  root = a;
		else add(a,b), add(b,a);
	}
	
	bfs(root);
	
	cin >> m;
	while(m--){
		int a, b;
		scanf("%d%d",&a,&b);
		int p = lca(a, b);
		if(p == a) cout << 1 << endl;
		else if(p == b) cout << 2 << endl;
		else cout << 0 << endl;
	}
	
	return 0;
}
