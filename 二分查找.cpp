//二分查找
#include<iostream>

using namespace std;
const int N = 100010;

int a[N];

int main(){
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	while(q--){
		int t;
		cin >> t;
		
		int l = 1,r = n;
		while(l < r){	//确定左边界可用左闭右开(先计算右边)
			int mid = (l+r)/2;
			if(a[mid] < t) l = mid + 1;
			else r = mid;
		}
		if(a[l] != t)
			cout << "-1 -1" << endl;
		else{
			cout << l << ' ';
			l = 1,r = n;
			while(l < r){	//确定右边界可用左开右闭(先计算左边)
				int mid = (l+r+1)/2;	//mid每次都要靠右
				if(a[mid] > t) r = mid - 1;
				else l = mid;
			}
			cout << l << endl;
		}
		
	}
	
	return 0;
}
