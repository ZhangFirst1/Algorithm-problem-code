//��������
//������������е��������Сֵ
#include<iostream>

using namespace std;
const int N = 100010;

int a[N],q[N],hh,tt = -1;

int main(){
	int n,k;
	cin >> n >> k;
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i - k + 1 > q[hh]) hh++;	//�����׳����ڣ�hh+1ά���������ڴ�С
		while(hh <= tt && a[i] <= a[q[tt]]) tt--;	//��β��������ɾȥ��β�����ϵ�ǰԪ�� 
		q[++tt] = i;	//�±�ӵ���β
		if(i + 1 >= k) printf("%d ",a[q[hh]]); 
	}
	
	cout << endl;
	hh = 0 , tt = -1;
	
	for(int i=0;i<n;i++){
		if(i - k + 1 > q[hh]) hh++;	//�����׳����ڣ�hh+1ά���������ڴ�С
		while(hh <= tt && a[i] >= a[q[tt]]) tt--;	//��β��������ɾȥ��β�����ϵ�ǰԪ�� 
		q[++tt] = i;	//�±�ӵ���β
		if(i + 1 >= k) printf("%d ",a[q[hh]]); 
	}	
	
	return 0;
}
