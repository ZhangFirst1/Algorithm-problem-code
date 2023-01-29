//并查集
#include<iostream>

using namespace std;
const int N = 100010;
int p[N];

int find(int x){
	if(p[x] == x) return x;
	return p[x] = find(p[x]);	//路径压缩，将x的祖宗当作他爹
}

void hebing(int a,int b){
	p[find(a)] = find(b);		//合并操作，将b的祖宗变成a的爹
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) p[i] = i;
	
	while(m--){
		char op[2];
		int a,b;
		scanf("%s%d%d",op,&a,&b);
		if(op[0] == 'M') hebing(a,b);
		else{
			if(find(a) == find(b)) cout << "Yes" <<endl;
			else cout << "No" << endl;
		}
	}
	
	return 0;
}
