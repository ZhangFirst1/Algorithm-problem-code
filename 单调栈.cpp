//����ջ
#include<iostream>

using namespace std;
const int N = 100010;
int stk[N],cnt;

int main(){
	int n;
	cin >> n;
	while(n--){
		int x;
		scanf("%d",&x);
		while(cnt && stk[cnt] >= x) cnt--; //���ջ��Ԫ�ش��ڵ�ǰ����ջԪ�أ����ջ
		
		if(!cnt) cout << "-1 "; 		 //���ջ�գ���û�бȸ�Ԫ��С��ֵ
		else cout << stk[cnt] << ' '; //ջ��Ԫ�ؾ�������ߵ�һ������С��Ԫ�ء�
		stk[++cnt] = x;
	}
	
	return 0;
}
