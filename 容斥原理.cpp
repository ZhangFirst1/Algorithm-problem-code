//����һ������ n �� m ����ͬ������ p1,p2,��,pm��
//������� 1��n ���ܱ� p1,p2,��,pm �е�����һ���������������ж��ٸ���

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long LL;
const int N = 21;
int p[N], n, m;

int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++) cin >> p[i];
	
	int res = 0;
	//ö�ٴ�1��111..(m��1)��ÿһ��״̬(����ѡ��һ������)
	for(int i=1;i< 1<<m;i++){
		int t = 1; //ѡ�м��϶�Ӧ�����ĳ˻�
		int s = 0; //ѡ�м��ϵ�����
		
		//ö�ٵ�ǰ״̬��ÿһλ
		for(int j=0;j<m;j++){
			//ѡ��һ������
			if(i >> j & 1){
				s++;
				//�˻�����n����n/t = 0,����ѭ��
				if((LL)t * p[j] > n){
					t = -1;
					break;
				}
				t *= p[j];
			}
		}
		if(t == -1) continue;
		
		if(s & 1) res += n/t; //ѡ������������, ���� n/tΪ��ǰ����״̬�ļ�������
		else res -= n/t;    //��֮���ȥ
		
	}
	cout << res << endl;
	return 0;
}
