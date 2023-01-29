//区间合并
//给定 n 个区间 [li,ri]，要求合并所有有交集的区间。
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int INF = 2e9;

vector<pair<int,int> >nums,res;
int main(){
	int st = -INF,ed = -INF;
	int n;
	cin >> n;
	while(n--){
		int l,r;
		scanf("%d%d",&l,&r);
		nums.push_back({l,r});
	}
	sort(nums.begin(),nums.end()); //按左端点排序
	
	for(auto num:nums){
		if(ed < num.first){		//1.两个区间无法合并
			if(ed != -INF) res.push_back({st,ed}); //区间1放进res数组
			st = num.first;		//维护区间2
			ed = num.second;
		}else if(ed < num.second) //2.两个区间可以合并，且区间1不包含区间2，区间2不包含区间1
			ed = num.second; //区间合并
			
		//3.区间1包含区间2 不需要操作
	}
	
	if(st != -INF && ed != -INF) res.push_back({st,ed});
	
	cout << res.size();
	return 0;
}
