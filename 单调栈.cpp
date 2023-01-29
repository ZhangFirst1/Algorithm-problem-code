//单调栈
#include<iostream>

using namespace std;
const int N = 100010;
int stk[N],cnt;

int main(){
	int n;
	cin >> n;
	while(n--){
		int x;
		scanf("%d",&x);
		while(cnt && stk[cnt] >= x) cnt--; //如果栈顶元素大于当前待入栈元素，则出栈
		
		if(!cnt) cout << "-1 "; 		 //如果栈空，则没有比该元素小的值
		else cout << stk[cnt] << ' '; //栈顶元素就是它左边第一个比它小的元素。
		stk[++cnt] = x;
	}
	
	return 0;
}
