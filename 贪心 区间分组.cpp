//�������
//���������䰴����˵��С��������
//��ǰ����ö�� �жϴ������Ƿ��ܷŽ���������
//heap�ж������䣬���ж�����
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
const int N = 100010;

int n;
struct Range{
	int l,r;
	bool operator< (const Range &W)const{
		return l < W.l;
	}
}range[N];

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		int l,r;
		cin >> l >> r;
		range[i] = {l,r};
	}
	
	sort(range+1,range+1+n); //������˵�����
	
	priority_queue<int , vector<int> , greater<int> > heap;	//heap�洢ÿ��������Ҷ˵�
	
	for(int i=1;i<=n;i++){
		//��heapΪ�ջ�ǰ�������˵����С���Ҷ˵㻹С�����¿�һ��
		if(heap.empty() || range[i].l <= heap.top()) heap.push(range[i].r);
		else{
			heap.pop();
			heap.push(range[i].r); //���¸������䳤��
		}
	}
	
	cout << heap.size();
	return 0;
}
