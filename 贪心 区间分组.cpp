//区间分组
//把所有区间按照左端点从小到大排序
//从前往后枚举 判断此区间是否能放进现有组中
//heap有多少区间，就有多少组
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
const int N = 100010;

int n;
struct Range{
	int l,r;
	bool operator< (const Range &W)const{
		return l < W.l;
	}
}range[N];

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		int l,r;
		cin >> l >> r;
		range[i] = {l,r};
	}
	
	sort(range+1,range+1+n); //按照左端点排序
	
	priority_queue<int , vector<int> , greater<int> > heap;	//heap存储每个组的最右端点
	
	for(int i=1;i<=n;i++){
		//当heap为空或当前区间的左端点比最小的右端点还小，则新开一组
		if(heap.empty() || range[i].l <= heap.top()) heap.push(range[i].r);
		else{
			heap.pop();
			heap.push(range[i].r); //更新该组区间长度
		}
	}
	
	cout << heap.size();
	return 0;
}
