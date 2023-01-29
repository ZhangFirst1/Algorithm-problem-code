#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
int n, a[N];
struct Point{
	double x,y;
}s[N];

bool cmp(Point a,Point b){
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool cmp1(int a,int b){
	return s[a].y < s[b].y;
}

double dist(int i,int j){
	double x = (s[i].x - s[j].x) * (s[i].x - s[j].x);
	double y = (s[i].y - s[j].y) * (s[i].y - s[j].y);
	return sqrt(x + y);
}

double Merge(int l,int r){	//分治求解
	double d = INF;
	if(l == r) return d;	//左右区间相等返回无穷
	if(l + 1 == r) return dist(l,r);
	
	int mid = (l+r) >> 1;
	double d1 = Merge(l, mid);
	double d2 = Merge(mid+1, r);
	d = min(d1, d2);
	
    int i, j, k = 0;
    for(i = l; i <= r; i++)
        if(fabs(s[mid].x - s[i].x) < d) 
            a[k++] = i;		//a表示所有距离中线不超过d的点
    
    sort(a, a+k, cmp1);
    
    for(i = 0;i < k; i++){
		for(j = i+1;j < k && s[a[j]].y - s[a[i]].y < d; j++){
			double d3 = dist(a[i], a[j]);
			if(d > d3) d = d3;
		}
	}
	return d;
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> s[i].x >> s[i].y;
	sort(s, s+n, cmp);
	printf("%.4lf\n", Merge(0,n-1));
	return 0;
}
