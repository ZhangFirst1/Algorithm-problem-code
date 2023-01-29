//��״���� ���
/*��������Ϊ N ������ A��Ȼ������ M �в���ָ�
��һ��ָ������ C l r d����ʾ�������е� l��r �������� d��
�ڶ���ָ������ Q x����ʾѯ�������е� x ������ֵ��
����ÿ��ѯ�ʣ����һ��������ʾ�𰸡�*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 100010;

int n,m;
int a[N];
LL tr[N];

int lowbit(int x){
	return x & -x;
}

void add(int x,int k){
	for(int i=x;i<=n;i+=lowbit(i)) tr[i] += k;
}

LL sum(int x){
	LL res = 0;
	for(int i=x; i ;i-=lowbit(i)) res += tr[i];
	return res;
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	//�ڵ�i��λ�ü��ϲ����״�����ֵ
	for(int i=1;i<=n;i++) add(i, a[i] - a[i-1]);
	
	while(m--){
		char op[2];
		int l,r,d;
		scanf("%s%d",op,&l);
		if(op[0] == 'C'){
			scanf("%d%d",&r,&d);
			//l~r + d �ȼ��� �������tr[l] + d; tr[r+1] - d;
			add(l,d); add(r+1,-d);
		}else{
			//ǰ׺��
			cout << sum(l) << endl;
		}
		
	}
	
	
	return 0;
}
