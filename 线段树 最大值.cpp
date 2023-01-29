//�߶���
//https://www.acwing.com/problem/content/description/1277/
/*��������Ϊ N ������ A���Լ� M ��ָ�ÿ��ָ���������������֮һ��
1.��Ӳ����������к����һ���������г��ȱ�� n+1��
2.ѯ�ʲ�����ѯ�������������� L �������������Ƕ��١�
*/

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
const int N = 2e5+10;
typedef long long LL;
int m,p;
//�߶����Ľڵ㣬���ռ俪4��
struct Node{
	int l,r;
	int v; //����[l,r]�����ֵ
}tr[4*N];

void pushup(int u){
	tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

//u��ʾ��ǰ�߶����Ľڵ���
void build(int u,int l,int r){
	tr[u] = {l,r};
	if(l == r) return;
	int mid = l + r >> 1;
	build(u << 1,l,mid); //����������
	build(u << 1 | 1,mid + 1 ,r); //����������
}
//��ѯ��uΪ���ڵ㣬����[l,r]�е����ֵ
int query(int u,int l,int r){
	//  Tl --- Tr
	// L -------- R
	// 1.���ط��Σ�ֱ�ӷ��� 
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].v;
	
	int mid = tr[u].l + tr[u].r >> 1;
	int v = 0; //���ֵ
	//  Tl---m---Tr
	//     L ------ R
	// 2.��Ҫ��tr��������[Tl,m]��������
	if(l <= mid) v = max(v,query(u << 1,l,r));
	
	//  Tl---m---Tr
	// L ------ R
	// 3.��Ҫ��tr��������[m+1,Tr]��������
	if(r > mid) v = max(v, query(u << 1 | 1 ,l, r));

	return v;
}

//uΪ�ڵ��ţ����¸ýڵ���������ֵ	
void modify(int u,int x,int v){
	if(tr[u].l == tr[u].r) tr[u].v = v; //Ҷ�ڵ㣬�ݹ����
	else{
		int mid = tr[u].l + tr[u].r >> 1;
		//����Ѱ��x���ڵ�����
		if(x <= mid) modify(u<<1, x, v);
		else modify(u << 1 | 1, x, v);
		//���ݣ����ӽڵ����Ϣ���¸��ڵ㣬��pushup����
		pushup(u);
	}
	
}


int main(){
	//n��ʾ���нڵ������last������һ�β�ѯ���
	int n = 0,last = 0;
	cin >> m >> p;
	//��ʼ���߶������ڵ���������Ϊ[1,m]
	build(1,1,m);
	
	while(m--){
		char op;
		cin >> op;
		if(op == 'A'){
			int t;
			cin >> t;
			//��n+1������
			modify(1, n+1, ((LL)t + last) % p); //��ĿҪ��
			//�ڵ����+1
			n++;
		}else{
			int l;
			cin >> l;
			//��ѯ[n - l + 1, n]�ڵ����ֵ,u=1,���Ӹ��ڵ㿪ʼ��ѯ
			last = query(1, n-l+1, n);
			cout << last << endl;
		}
	}
	
	return 0;
}
