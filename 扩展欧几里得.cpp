#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
int a,b,x,y;

int exgcd(int a,int b,int &x,int &y){
    if(b == 0){ //b = 0, ax+0y=a, 所以x=1,y=0为一组解
        x = 1, y = 0;
        return a;
    } 
    int d = exgcd(b, a%b, y, x); //by + (a%b)x = d  //a mod b = a - (a/b)*b
	y -= a / b * x; 			 //ax - b(y - a/b*x) = d
    return d;
}

int main(){
    int t;
    cin >> t;
//  while(t--){
//      cin >> a >> b;
//      exgcd(a,b,x,y);
//      cout << x << ' ' << y << endl;
//  }
//    线性同余方程求解
    while(t--){
		int a, b, m;
		cin >> a >> b >> m;
		int x, y;
		//ax 同余 b(mod m)
		//ax 同余 b + my (mod m)
		//ax - my 同余 b (mod m)
		//令y撇等于y
		//ax + my撇 同余 b
		int d = exgcd(a, m, x, y);
		if(b % d != 0) puts("impossible"); //如果b不为d的倍数则无解
		else printf("%lld\n", (LL)x * (b / d) % m);
	}
  
    return 0;
}
