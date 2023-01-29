//奇偶游戏
//用sum数组表示s的前缀和，s[L~R]有偶数个1，等价于sum[L-1]与sum[R]奇偶性相同
//s[l~R]有奇数个1，等价于sum[L-1]与sum[R]奇偶性不同
//d[x]为0表示x与fa[x]奇偶性相同，为1则不同
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
		d[x] ^= d[fa[x]]; //对x到树根路径上所有边权做异或运算，可得x与树根的奇偶关系
		fa[x] = root;
	}
	return fa[x];
}

int main(){
	cin >> n >> m;
	n = 0;
	
	for(int i=0;i<N;i++) fa[i] = i;
	
	int res = m; //无矛盾就输出m
	for(int i=1;i<=m;i++){
		int a,b;
		string type;
		cin >> a >> b >> type;
		a = get(a-1), b = get(b); //s[a-1] s[b]
		
		int t = 0;
		if(type == "odd") t = 1; //odd答案为1（奇）
		int pa = find(a), pb = find(b);
		if(pa == pb){ //检查x y是否在同一集合(奇偶关系是否已知)
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
