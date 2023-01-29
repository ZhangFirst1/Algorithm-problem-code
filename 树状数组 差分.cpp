//树状数组 差分
/*给定长度为 N 的数列 A，然后输入 M 行操作指令。
第一类指令形如 C l r d，表示把数列中第 l～r 个数都加 d。
第二类指令形如 Q x，表示询问数列中第 x 个数的值。
对于每个询问，输出一个整数表示答案。*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 100010;

int n,m;
int a[N];
LL tr[N];

int lowbit(int x){
	return x & -x;
}

void add(int x,int k){
	for(int i=x;i<=n;i+=lowbit(i)) tr[i] += k;
}

LL sum(int x){
	LL res = 0;
	for(int i=x; i ;i-=lowbit(i)) res += tr[i];
	return res;
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	//在第i个位置加上差分树状数组的值
	for(int i=1;i<=n;i++) add(i, a[i] - a[i-1]);
	
	while(m--){
		char op[2];
		int l,r,d;
		scanf("%s%d",op,&l);
		if(op[0] == 'C'){
			scanf("%d%d",&r,&d);
			//l~r + d 等价于 差分数组tr[l] + d; tr[r+1] - d;
			add(l,d); add(r+1,-d);
		}else{
			//前缀和
			cout << sum(l) << endl;
		}
		
	}
	
	
	return 0;
}
