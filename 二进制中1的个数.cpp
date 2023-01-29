//二进制中1的个数
#include<iostream>

using namespace std;
//lowbit操作截取一个数字最后一个1后面的所有位
int lowbit(int x){
	return x&(-x);	//原码与补码(反码+1)按位与得到1后面所有位
}

int main(){
	int n;
	cin >> n;
	
	while(n--){
		int x;
		cin >> x;
		
		int res = 0;
		while(x){
			x -= lowbit(x);
			res++;
		}
		cout << res << endl;
	}
		
	return 0;
}
