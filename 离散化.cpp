#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
const int N = 300010;
typedef pair<int,int> PII;
typedef long long LL;

int a[N], s[N];
vector<int> alls;
vector<PII> add, query;
int n, m;

int find(int x){
	int l = 0, r =alls.size() - 1;
	while(l < r){
		int mid = (l+r) >> 1;
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
}

vector<int>:: iterator unique(vector<int> &a){
	int j = 0;
	for(int i=0;i < a.size();i++)
		if(!i || a[i] != a[i-1])
			a[j++] = a[i];
	return a.begin() + j;
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		
		alls.push_back(x);
	}
	for(int i=1;i<=m;i++){
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});
		
		alls.push_back(l);
		alls.push_back(r);
	}
	
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls), alls.end());
	
	for(auto item : add){
		int x = find(item.first);
		a[x] += item.second;
	}
	
	for(int i=1;i<=alls.size();i++) s[i] = s[i-1] + a[i];
	
	for(auto item:query){
		int l = find(item.first), r = find(item.second);
		cout << s[r] - s[l-1] << endl;
	}
	
	return 0;
}
