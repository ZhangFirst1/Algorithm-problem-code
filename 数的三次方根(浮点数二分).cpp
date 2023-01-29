//数的三次方根(浮点数二分)
#include<iostream>

using namespace std;

int main(){
	double n;
	cin >> n;
	double l = -10000, r = 10000;
	
	while(r - l > 1e-8){
		double mid = (l+r)/2;
		if(mid*mid*mid >= n) r = mid;
		else l = mid;
	}
	
	printf("%.6f",l);
	
	return 0;
}
