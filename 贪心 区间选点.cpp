//����ѡ�� ѡ�����ٵĿ��Ը�����������ĵ�
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 100010;

int n;
struct Range{
	int l,r;
}range[N];

bool cmp(Range a,Range b){
	return a.r < b.r;
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> range[i].l >> range[i].r;
	
	sort(range+1,range+1+n,cmp); //�Ҷ˵��С��������
	
	int res = 0 , ed = -2e9;
	for(int i=1;i<=n;i++){
		if(ed < range[i].l){
			res++;
			ed = range[i].r;
		}
	}
	
	cout << res;
	return 0;
}
