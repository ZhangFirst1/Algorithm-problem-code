//�������㷨 ����ͼ�����ƥ��
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 510,M = 100010;

int n1,n2,m,cnt,head[M];
struct edges{
	int to,next,w;
}edge[M];
int match[N]; //��ʾƥ���ϵ
bool st[N];

void add(int x,int y){
	edge[++cnt].to = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
}

bool find(int x){
	for(int i=head[x]; i ;i = edge[i].next){
		int to = edge[i].to;
		if(!st[to]){	//���Ҳ�Ԫ��δ�����ʹ�
			st[to] = true;
			if(match[to] == 0 || find(match[to])){	//�������ƥ�䣬����ԭ��ƥ������Ԫ�ؿ����ҵ��µ�ƥ��
				match[to] = x; //����ƥ���ϵ
				return true;
			}
			
		}
	}
	return false;
}

int main(){
	cin >> n1 >> n2 >> m;
	while(m--){
		int a,b;
		cin >> a >>b;
		add(a,b);
	}
	
	int res = 0;
	for(int i=1;i<=n1;i++){
		memset(st, false ,sizeof st);
		if(find(i)) res++;
	}
	
	cout << res;
	return 0;
}
