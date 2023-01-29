//Ⱦɫ���ж϶���ͼ dfs
//�����е�ֳ��������ϣ�ʹ�����б�ֻ�����ڼ���֮�䣬���Ƕ���ͼ
//����ͼ��һ�������������������ܰ�������Ϊż���Ļ��� ��һ������ͨͼ
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 2e5+10;
int e[N],ne[N],idx,h[N];
int n,m;
int st[N];

void add(int a,int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u,int color){
	st[u] = color;	//��ǰ�����ɫΪcolor
	
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		if(!st[j]){	//j��δȾɫ
			if(!dfs(j, 3 - color)) return false;	
		}else if(st[j] == color) return false;	//���һ���ߵ���������ɫ��ͬ����󣬷���false
	}
	return true;
}

int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m--){
		int a,b;
		cin >> a >> b;
		add(a,b); add(b,a); //����ͼ
	}
	
	bool flag = true;
	for(int i=1;i<=n;i++){	//�������е�
		if(!st[i]){			//ÿ�ν�δȾɫ�ĵ�dfs
			if(!dfs(i,1)){	//Ĭ��Ⱦ��1��2,dfs����ì����Ϊ����ͼ
				flag = false;
				break;
			}
		}
	}
	
	if(flag) cout << "Yes";
	else cout << "No";
	
	return 0;
}
