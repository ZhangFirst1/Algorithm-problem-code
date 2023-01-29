//��ϣ��(����Ѱַ��)
#include<iostream>
#include<cstring>

using namespace std;
const int N = 2e5+3; //����Ѱַ��һ�㿪 ���ݷ�Χ�� 2~3��, ��������ʾ�û�г�ͻ��
const int null = 0x3f3f3f3f;

int h[N];

int find(int x){
	int k = (x % N + N) % N;
	while(h[k] != null && h[k] != x){	//������λ�ò�Ϊ���Ҳ�Ϊx
		k++;
		if(k == N) k = 0;	//���������һ��λ�ã�ѭ����һ��
	}
	return k; //���x�ڹ�ϣ���У�k����x���±ꣻ������ڣ�k����xӦ�ô洢��λ��
}

int main(){
	int n;
	cin >> n;
	
	memset(h, 0x3f ,sizeof h);	//�涨��ָ��Ϊ0x3f3f3f3f
	
	while(n--){
		string op;
		int x;
		cin >> op >> x;
		if(op == "I") h[find(x)] = x;
		else{
			if(h[find(x)] == null) cout << "No" <<endl;
			else cout << "Yes" << endl;
		}
		
	}
		
	return 0;
}
