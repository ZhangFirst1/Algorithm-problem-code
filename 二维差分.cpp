//��ά���
//����һ�� n �� m �е��������������� q ��������ÿ����������������� x1,y1,x2,y2,c��
//���� (x1,y1) �� (x2,y2) ��ʾһ���Ӿ�������Ͻ���������½����ꡣ
//ÿ��������Ҫ��ѡ�е��Ӿ����е�ÿ��Ԫ�ص�ֵ���� c��
#include<iostream>

using namespace std;
const int N = 1e3+10;

int a[N][N],b[N][N];

void Insert(int x1,int y1,int x2,int y2,int c){
	b[x1][y1] += c;
	b[x1][y2+1] -= c;
	b[x2+1][y1] -= c;
	b[x2+1][y2+1] += c;
}

int main(){
	int n,m,q;
	cin >> n >> m >> q;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) 
			scanf("%d",&a[i][j]);
			
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			Insert(i,j,i,j,a[i][j]);	//�����������
	
	while(q--){
		int x1,y1,x2,y2,c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		Insert(x1,y1,x2,y2,c);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j] = b[i-1][j] + b[i][j-1] + b[i][j] - b[i-1][j-1]; //����b��a�Ĳ�֣���ֱ��������b������
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
