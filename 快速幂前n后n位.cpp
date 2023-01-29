#include<cstdio>
#include<cmath>
typedef long long ll;
using namespace std;

ll n,k;
const ll mod=1000;
ll quick_pow(ll a,ll b)
{
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int  main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld %lld",&n,&k);
		double p=k*log10(n);
		p=p-(int)p;
		printf("Case %d: %lld",i,(ll)(pow(10,p)*100));
		printf(" %03lld\n",quick_pow(n,k));
	}	
	return 0;
} 
