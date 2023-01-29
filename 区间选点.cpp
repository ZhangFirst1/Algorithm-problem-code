#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1e5+10;

struct Node{
	int l,r;
	friend operator<(const Node& a,const Node& b){
		return a.r < b.r;
	}
}a[N];

int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i].l >> a[i].r;
	int cnt = 0, ed = -2e9;
	for(int i=1;i<=n;i++){
		if(a[i].l > ed){
			ed = a[i].r;
			cnt++;
		}
	}
	
	cout << cnt << endl;
	return 0;
}
