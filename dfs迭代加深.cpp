/*��������
	����������֧�ܶ����λ��ĳ���Ƚ�ǳ�Ľڵ�ʱ����ͨdfs�����ڴ����֧�˷Ѻܶ�ʱ��
	�������������������ǰ�ҵ���
	�����ӳ�����
	https://www.acwing.com/solution/content/38248/
*/
#include<iostream>
#include<cstring>

using namespace std;
const int N = 110;

int path[N],n;
bool st[N]; //�����ų���Ч����

bool dfs(int u,int k){ //u��ǰ��ȣ�k������
	if(u > k) return false;
	if(path[u-1] == n) return true;
	
	memset(st, 0, sizeof st);
	
	for(int i=u-1;i>=0;i--) //����ǵ�ǰ�ģ����Դ�u-1��ʼ
		for(int j=i;j>=0;j--){
			int s = path[i] + path[j];
			if(s > n || s <= path[u-1] || st[s]) continue; //path��������
			st[s] = true;
			path[u] = s;
			if(dfs(u+1,k)) return true;
		}
	return false;
}

int main(){
	
	path[0] = 1;
	
	while(cin >> n , n){
		int k = 1;
		while(!dfs(1,k)){
			k++;
		}
		for(int i=0;i<k;i++) cout << path[i] << ' ';
		cout << endl;
	}
	
	return 0;
}
