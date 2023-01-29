#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 100010;

int h[N]; 	//��
int ph[N];	//��i������ĵ���±�(ͨ���±��Ҷ��е��±�)ph[idx] = k	�ڵ�ֵh[ph[idx]]
int hp[N];	//���е�Ĳ������(�������Ӧ��ph�����е�idx, hp[u] = idx)
int n, m, cur_size;	//m��¼����ĸ�����cur_sizeά����ǰ���е�ĸ���

void heap_swap(int u,int v){
	swap(h[u], h[v]);	//�����������ֵ
	swap(hp[u], hp[v]);	//����ph���±�
	swap(ph[hp[u]], ph[hp[v]]);	//������������±�
}

void down(int u){
	int t = u;
	if(u*2 <= cur_size && h[t] > h[u*2]) t = u*2;
	if(u*2+1 <= cur_size && h[t] > h[u*2+1]) t = u*2+1;
	           
	if(t != u){
		heap_swap(t, u);
		down(t);
	}
}

void up(int u){
	if(u/2 > 0 && h[u/2] > h[u]){
		heap_swap(u, u/2);
		up(u/2);
	}
}

int main(){
	cin >> n;
	while(n--){
		string op;
		int k, x;
		cin >> op;
		if(op == "I"){
			cin >> x;
			m++;
			h[++cur_size] = x;
			ph[m] = cur_size; //��m������ĵ���±�Ϊcur_size;
			hp[cur_size] = m; //���е�Ĳ���˳��
			up(cur_size);
		}else if(op == "PM") cout << h[1] << endl;
		else if(op == "DM"){
			heap_swap(1, cur_size);
			cur_size--;
			down(1);
		}else if(op == "D"){		//ɾ����k���������
			cin >> k;
			int u = ph[k];			//����u�����k������ĵ���±�
			heap_swap(u, cur_size);	//��Ϊ�˴�������ph[k]��ֵ�Ѿ��ı�
			cur_size--;				
			up(u);		
			down(u);
		}else if(op == "C"){		//�޸ĵ�k���������
			cin >> k >> x;
			h[ph[k]] = x;
			down(ph[k]);	//ע��up��down�����õ��Ƕ��е��±꣬��ph[k]
			up(ph[k]);
		}
		
		
	}
	return 0;
}
