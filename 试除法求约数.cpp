#include<iostream>
#include<algorithm>

using namespace std;
const int N = 10010;

int a[N];

void yueshu(int n){
	int cnt = 0;
	for(int i=1;i<=n/i;i++){
		if(n % i == 0){
			a[++cnt] = i;	
		
			if(i != n/i) a[++cnt] = (n/i);
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++) cout << a[i] << ' ';
	cout << endl;
} 

int main(){
	int n;
	cin >> n;
	
	while(n--){
		int t;
		cin >> t;
		yueshu(t);
		
	}
	
	return 0;
}
