//��״���� ���
/*����һ������Ϊ N ������ A���Լ� M ��ָ�ÿ��ָ���������������֮һ��
1. C l r d����ʾ�� A[l],A[l+1],��,A[r] ������ d��
2. Q l r����ʾѯ�������е� l��r �����ĺ͡�
����ÿ��ѯ�ʣ����һ��������ʾ�𰸡�*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 100010;

int n,m;
int a[N];
LL tr1[N]; //ά��b[i]��ǰ׺��
LL tr2[N]; //ά��i*b[i]��ǰ׺��

int lowbit(int x){
	return x & -x;
}

void add(LL tr[],int x,LL k){
	for(int i=x;i<=n;i += lowbit(i)) tr[i] += k;
}

LL sum(LL tr[],int x){
	LL res = 0;
	for(int i=x;i;i -= lowbit(i)) res += tr[i];
	return res;
}

//��ǰ׺��ʱ a1+..+ax = b1 + (b1+b2) + ... + (b1+..+bn)
//�����ò���˼�� = (b1+...+bn) * (n+1) - (b1 - 2*b2 - ... n*bn)
//����Ҫά����ǰ׺��
LL prefix_sum(int x){
	return sum(tr1,x) * (x+1) - sum(tr2, x); 
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++){
		int b = a[i] - a[i-1];
		add(tr1, i, b);
		add(tr2, i, (LL)b*i);
	}
	
	while(m--){
		char op[2];
		int l,r,d;
		scanf("%s%d%d",op,&l,&r);
		if(op[0] == 'Q'){
			//��ǰ׺��
			cout << prefix_sum(r) - prefix_sum(l - 1) << endl;
		}else{
			cin >> d;
			//a[l] += d;
			add(tr1,l,d); add(tr2,l,l*d);
			//a[r+1] -= d
			add(tr1,r+1,-d); add(tr2,r+1,-d*(r+1));
		}
	}
	
	
	return 0;
}
