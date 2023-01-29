//¿ìËÙÅÅĞò
#include<iostream>

using namespace std;
const int N = 100010;

int a[N];

void quicksort(int l, int r){
	int t = a[(l+r)/2];
	
	if(l >= r) return;
	
	int i = l,j = r;
	while(i <= j){
		while(a[i] < t) i++;
		while(a[j] > t) j--;
		if(i <= j){
			swap(a[i],a[j]);
			i++;	j--;
		}
	}
	quicksort(l,j);
	quicksort(i,r);	
}

int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	quicksort(1,n);
	
	for(int i=1;i<=n;i++) cout << a[i] << ' ';
	
	return 0;
}
