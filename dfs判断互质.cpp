//给定 n 个正整数，将它们分组，使得每组中任意两个数互质。
//至少要分成多少个组？

#include<iostream>

using namespace std;
const int N = 15;

int p[N],n,ans = N;
int g[N][N];
bool st[N];

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;
}

bool check(int g[],int x,int start){
	for(int i=0;i<start;i++){
		if(gcd(g[i],x) > 1) return false; 
	}
	return true;
}

//当前要分在哪个组，要分在该组第几个位置，从哪个位置选(组合)，当前分了几个数
void dfs(int gr,int gc,int start,int cnt){
	if(gr >= ans) return; //剪枝+防止死循环
	if(cnt == n) ans = gr;
	
	bool flag = true; //从start开始寻找，是否能有元素放在gr组中
	
	for(int i=start;i<n;i++){
		if(!st[i] && check(g[gr],p[i],gc)){ //判断该组前边所有元素是否与当前搜索的元素互质
			st[i] = true;
			g[gr][gc] = p[i];
			dfs(gr,gc+1,i+1,cnt+1);
			st[i] = false;
			flag = false;
		}
	}
	
	//新开分组
	if(flag) dfs(gr+1,0,0,cnt);	
}

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++) cin >> p[i];
	
	dfs(1,0,0,0);
	
	cout << ans;
	
	return 0;
}
