//��������
//ÿ��ɾ��һ�����Ϊ 0 �ĵ㣬��ˢ�����������ȱ߸�����
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int N = 100010;

int ne[N],e[N],h[N],idx;
int cnt,d[N],top[N];	//top����������,dΪ���,cnt��¼top���ж���Ԫ��
int n,m;

void add(int a,int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort(){
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(d[i] == 0)
			q.push(i); //���������Ϊ0�ĵ����
	
	while(q.size()){
		int t = q.front();
		top[++cnt] = t;
		q.pop();
		
		for(int i=h[t];i != -1;i = ne[i]){
			int j = e[i];
			d[j]--;	//j�����--
			if(d[j] == 0) q.push(j);
		}
	}
	if(cnt == n) return true;
	return false;
}

int main(){
	cin >> n >> m;
	memset(h,-1,sizeof h);
	
	while(m--){
		int a,b;
		cin >> a >> b;
		add(a,b);
		d[b]++;
	}
	
	if(topsort() == 0) cout << "-1" ;
	else{
		for(int i=1;i<=n;i++)
			cout << top[i] << ' ';
	}	
	
	
	return 0;
}
