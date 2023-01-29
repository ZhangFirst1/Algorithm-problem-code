/*˫��dfs
	��������������˷�ʱ�䣬�ӳ�̬����̬����һ�룬���ս���
	
	������
	https://www.acwing.com/solution/content/38250/
*/
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 46;
int n,m,k,ans;
int w[N];
int weight[1 << 25],cnt = 1;

void dfs1(int u,int s){
	if(u == k){
		weight[cnt++] = s; //weigh[0]��0�����Դճ�����0
		return;
	}
	//ö�ٵ�ǰ��ѡ�����Ʒ
	dfs1(u+1,s);
	//ѡ�����Ʒ
	if((LL)s + w[u] <= m) dfs1(u+1,s+w[u]); //�����Լ�֦
}

void dfs2(int u,int s){
	if(u >= n){ //������n���ڵ㣬����һ��
		int l = 0,r = cnt - 1;
		while(l < r){
			int mid = (l+r+1) / 2;
			if(weight[mid] > m - s) r = mid - 1;
			else l = mid;
			
		}
		ans = max(ans,weight[l] + s);
		return;
	}
	dfs2(u+1,s);
	
	if((LL)s + w[u] <= m) dfs2(u+1,s+w[u]);
}

int main(){
	cin >> m >> n;
	for(int i=0;i<n;i++) cin >> w[i];
	
	sort(w,w+n);
	reverse(w,w+n);
	
	k = n/2+2; //��ǰk����Ʒ������ɵ��������
	dfs1(0,0);
	
	sort(weight,weight + cnt);
	cnt = unique(weight,weight + cnt) - weight;
	//��k��ʼ ��ǰ����0
	dfs2(k,0);
	
	cout << ans << endl;
	return 0;
}
