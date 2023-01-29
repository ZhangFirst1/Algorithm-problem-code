//堆排序
#include<iostream>

using namespace std;
const int N = 100010;

int n,m;
int size,h[N];

void down(int u){
	int t = u;	//t表示父节点与子节点的最小值的下标
	
	if(u*2 <= size && h[u*2] <= h[t]) t = u*2;
	if(u*2+1 <= size && h[u*2+1] <= h[t]) t = u*2+1;
	
	if(u != t){	//最小值是u的子节点
		swap(h[t],h[u]);	
		down(t);	//继续down子节点 
	}
}

void up(int u){	
	if(u/2 > 0 && h[u/2] > h[u]){	//如果父节点存在且父节点大于子节点
		swap(h[u/2],h[u]);
		u /= 2;
	}
}

int main(){			
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> h[i];
	size = n;
	
	for(int i=n/2;i>0;i--) down(i);	//创建堆(从n/2开始down,因为叶子节点一定满足堆的性质)
	//for(int i=1;i<=n/2;i++) down(i); 不可以从根节点开始down，因为down操作必须满足：左右儿子满足堆的性质
	
	for(int i=1;i<=m;i++){
		cout << h[1] << ' ';
		
		h[1] = h[size--];	//输出后删除堆顶
		down(1);
	}
	
	
	return 0;
}
