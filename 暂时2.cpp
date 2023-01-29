#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 10010;



void change(int f[10]){
	f[1] = 10;
	
}

int main(){
	int f[N];
	f[1] = 1;
	change(f);
	cout << f[1] << endl;
	return 0;
}
