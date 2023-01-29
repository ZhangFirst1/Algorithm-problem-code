//树状数组 差分
/*给定一个长度为 N 的数列 A，以及 M 条指令，每条指令可能是以下两种之一：
1. C l r d，表示把 A[l],A[l+1],…,A[r] 都加上 d。
2. Q l r，表示询问数列中第 l～r 个数的和。
对于每个询问，输出一个整数表示答案。*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 100010;

int n,m;
int a[N];
LL tr1[N]; //维护b[i]的前缀和
LL tr2[N]; //维护i*b[i]的前缀和

int lowbit(int x){
	return x & -x;
}

void add(LL tr[],int x,LL k){
	for(int i=x;i<=n;i += lowbit(i)) tr[i] += k;
}

LL sum(LL tr[],int x){
	LL res = 0;
	for(int i=x;i;i -= lowbit(i)) res += tr[i];
	return res;
}

//求前缀和时 a1+..+ax = b1 + (b1+b2) + ... + (b1+..+bn)
//可运用补的思想 = (b1+...+bn) * (n+1) - (b1 - 2*b2 - ... n*bn)
//所以要维护俩前缀和
LL prefix_sum(int x){
	return sum(tr1,x) * (x+1) - sum(tr2, x); 
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++){
		int b = a[i] - a[i-1];
		add(tr1, i, b);
		add(tr2, i, (LL)b*i);
	}
	
	while(m--){
		char op[2];
		int l,r,d;
		scanf("%s%d%d",op,&l,&r);
		if(op[0] == 'Q'){
			//求前缀和
			cout << prefix_sum(r) - prefix_sum(l - 1) << endl;
		}else{
			cin >> d;
			//a[l] += d;
			add(tr1,l,d); add(tr2,l,l*d);
			//a[r+1] -= d
			add(tr1,r+1,-d); add(tr2,r+1,-d*(r+1));
		}
	}
	
	
	return 0;
}
