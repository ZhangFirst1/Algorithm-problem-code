//RMQ问题（区间最值）
//ST算法
#include<iostream>
#include<cmath>

using namespace std;
const int N = 1e6+10;
const int M = 22; //log(N) < 20

int a[N];
int f[N][M]; //f[i][j]表示从i位起的2^j个数中的最大数
//快读
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main(){
	int n, m, x, y;
	n = read(); m = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		f[i][0] = a[i]; //f[i][0]表示[i,i]中的最大值，只能是a[i]，故f[i][0]=a[i]
	}
	
	int t = log2(n);
	for(int j=1;j<=t;j++)
		for(int i=1;i+(1<<j)-1 <= n;i++)
			f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);	//将长度为2^j的区间分为长度为2^(j-1)的两部分
	
	while(m--){
		x = read(); y=read();
		int k = log2(y-x+1);
		printf("%d\n",max(f[x][k], f[y-(1<<k)+1][k])); //区间 [x,y]=[x,x+2^k-1]∪[y-2^k+1,y]
	}
	
	return 0;
}
