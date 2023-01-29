//��ż��Ϸ
//��sum�����ʾs��ǰ׺�ͣ�s[L~R]��ż����1���ȼ���sum[L-1]��sum[R]��ż����ͬ
//s[l~R]��������1���ȼ���sum[L-1]��sum[R]��ż�Բ�ͬ
//d[x]Ϊ0��ʾx��fa[x]��ż����ͬ��Ϊ1��ͬ
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;
const int N = 2e4+10;

int fa[N],d[N],n,m;
unordered_map<int,int> S;

int get(int x){
	if(S.count(x) == 0) S[x] = ++n;
	return S[x];
}

int find(int x){
	if(fa[x] != x){
		int root = find(x);
		d[x] ^= d[fa[x]]; //��x������·�������б�Ȩ��������㣬�ɵ�x����������ż��ϵ
		fa[x] = root;
	}
	return fa[x];
}

int main(){
	cin >> n >> m;
	n = 0;
	
	for(int i=0;i<N;i++) fa[i] = i;
	
	int res = m; //��ì�ܾ����m
	for(int i=1;i<=m;i++){
		int a,b;
		string type;
		cin >> a >> b >> type;
		a = get(a-1), b = get(b); //s[a-1] s[b]
		
		int t = 0;
		if(type == "odd") t = 1; //odd��Ϊ1���棩
		int pa = find(a), pb = find(b);
		if(pa == pb){ //���x y�Ƿ���ͬһ����(��ż��ϵ�Ƿ���֪)
			if((d[a] ^ d[b]) != t){
				res = i - 1;
				break;
			}
		}else{
			fa[pa] = pb;
			d[pa] = d[a] ^ d[b] ^ t;
		}
		
	}
	cout << res;
	return 0;
}
