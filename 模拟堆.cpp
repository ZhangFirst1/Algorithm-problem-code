#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 100010;

int h[N]; 	//堆
int ph[N];	//第i个插入的点的下标(通过下标找堆中的下标)ph[idx] = k	节点值h[ph[idx]]
int hp[N];	//堆中点的插入次序(堆数组对应的ph数组中的idx, hp[u] = idx)
int n, m, cur_size;	//m记录插入的个数，cur_size维护当前堆中点的个数

void heap_swap(int u,int v){
	swap(h[u], h[v]);	//交换堆数组的值
	swap(hp[u], hp[v]);	//交换ph的下标
	swap(ph[hp[u]], ph[hp[v]]);	//交换堆数组的下标
}

void down(int u){
	int t = u;
	if(u*2 <= cur_size && h[t] > h[u*2]) t = u*2;
	if(u*2+1 <= cur_size && h[t] > h[u*2+1]) t = u*2+1;
	           
	if(t != u){
		heap_swap(t, u);
		down(t);
	}
}

void up(int u){
	if(u/2 > 0 && h[u/2] > h[u]){
		heap_swap(u, u/2);
		up(u/2);
	}
}

int main(){
	cin >> n;
	while(n--){
		string op;
		int k, x;
		cin >> op;
		if(op == "I"){
			cin >> x;
			m++;
			h[++cur_size] = x;
			ph[m] = cur_size; //第m个插入的点的下标为cur_size;
			hp[cur_size] = m; //堆中点的插入顺序
			up(cur_size);
		}else if(op == "PM") cout << h[1] << endl;
		else if(op == "DM"){
			heap_swap(1, cur_size);
			cur_size--;
			down(1);
		}else if(op == "D"){		//删除第k个插入的数
			cin >> k;
			int u = ph[k];			//先用u保存第k个插入的点的下标
			heap_swap(u, cur_size);	//因为此处操作后ph[k]的值已经改变
			cur_size--;				
			up(u);		
			down(u);
		}else if(op == "C"){		//修改第k个插入的数
			cin >> k >> x;
			h[ph[k]] = x;
			down(ph[k]);	//注意up和down操作用的是堆中的下标，即ph[k]
			up(ph[k]);
		}
		
		
	}
	return 0;
}
