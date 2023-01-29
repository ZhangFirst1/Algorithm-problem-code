//https://www.acwing.com/problem/content/244/
//�߶��������޸Ĳ���
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long LL;
const int N = 100010;
int n,m;
int w[N];
struct Tree{
	int l,r;
	LL sum,add;
}tr[N];

void pushup(int u){
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
	auto &root = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
	if(root.add){ //������������
		l.add += root.add, l.sum += (LL)(l.r - l.l + 1) * root.add;//���ҽڵ������Ǽ��ϸ��ڵ�������(����������´�)
		r.add += root.add, r.sum += (LL)(r.r - r.l + 1) * root.add;
		root.add = 0; //ȥ�����ڵ�������
	}
}

void build(int u,int l,int r){
	if(l == r) tr[u] = {l,r,w[r],0};
	else{
		tr[u] = {l,r};
		int mid = (l+r) >> 1;
		build(u << 1,l,mid);	build(u << 1 | 1,mid+1,r);
		pushup(u);   //�ı����������������¸��ڵ�
	}
}

void modify(int u,int l,int r,int d){
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * d; //�����ǰ������ȫ�ڴ��޸������ڣ�ֱ���޸������ܺ�
		tr[u].add += d;	//�����
	}else{ //��������
		pushdown(u); //��������ı�ǲ�һ������Ҫ�Ƚ���ǰ�ı�ǳ��´�
		int mid = (tr[u].l + tr[u].r) >> 1;
		if(l <= mid) modify(u << 1,l,r,d); //����������
		if(r > mid) modify(u << 1 | 1,l,r,d);//����������
		pushup(u); //�������޸�����¸�����
	}
}

LL query(int u,int l,int r){
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
	
	pushdown(u); //��ѯʱ��pushdown����ǰ���
	int mid = (tr[u].l + tr[u].r) >> 1;
	LL sum = 0;
	if(l <= mid) sum += query(u << 1,l,r);
	if(r > mid) sum += query(u << 1 | 1,l,r);
	return sum;
}


int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> w[i];
	
	build(1,1,n);
	//C l r d����ʾ�� A[l],A[l+1],��,A[r] ������ d��
	//Q l r����ʾѯ�������е� l��r �����ĺ͡�
	char op[2];
	int l,r,d;
	while(m--){
		scanf("%s%d%d",op,&l,&r);
		if(op[0] == 'C'){
			cin >> d;
			modify(1,l,r,d);
		}else{
			cout << query(1,l,r) << endl; 
		}
	}
	
	return 0;
}
