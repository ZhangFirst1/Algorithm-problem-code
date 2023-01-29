//区间覆盖
//给定 N 个闭区间 [ai,bi] 以及一个线段区间 [s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。
//输出最少区间数，如果无法完全覆盖则输出 -1
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
const int N = 100010;

struct Range{
	int l,r;
	bool operator< (const Range &W)const{
		return l < W.l;
	}
}range[N];

int main(){
	int st,ed;
	cin >> st >> ed;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int l,r;
		cin >> l >> r;
		range[i] = {l,r};
	}
	sort(range+1, range+1+n);
	
	int res = 0;
	bool flag = false;
	//在左端点都小于st的情况下，取右端点最大的区间
	for(int i=1;i<=n;i++){
		int j = i, r = -2e9;
		while(j <= n && range[j].l <= st){
			r = max(r, range[j].r);
			j++;
		}
		if(r < st){ //如果区间都小于st则无法覆盖
			break;
		}
		res++; //使用该区间覆盖
		if(r >= ed){ //区间已经大于ed，已经可以覆盖，结束循环
			flag = true;
			break;
		}
		
		st = r; //更新起点
		i = j - 1; //转调至当前区间(循环里有i++,所以等于j-1)
	}
	
	if(!flag) cout << -1;
	else cout << res;
	return 0;
}
