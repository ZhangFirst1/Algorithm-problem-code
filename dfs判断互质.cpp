//���� n ���������������Ƿ��飬ʹ��ÿ�����������������ʡ�
//����Ҫ�ֳɶ��ٸ��飿

#include<iostream>

using namespace std;
const int N = 15;

int p[N],n,ans = N;
int g[N][N];
bool st[N];

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;
}

bool check(int g[],int x,int start){
	for(int i=0;i<start;i++){
		if(gcd(g[i],x) > 1) return false; 
	}
	return true;
}

//��ǰҪ�����ĸ��飬Ҫ���ڸ���ڼ���λ�ã����ĸ�λ��ѡ(���)����ǰ���˼�����
void dfs(int gr,int gc,int start,int cnt){
	if(gr >= ans) return; //��֦+��ֹ��ѭ��
	if(cnt == n) ans = gr;
	
	bool flag = true; //��start��ʼѰ�ң��Ƿ�����Ԫ�ط���gr����
	
	for(int i=start;i<n;i++){
		if(!st[i] && check(g[gr],p[i],gc)){ //�жϸ���ǰ������Ԫ���Ƿ��뵱ǰ������Ԫ�ػ���
			st[i] = true;
			g[gr][gc] = p[i];
			dfs(gr,gc+1,i+1,cnt+1);
			st[i] = false;
			flag = false;
		}
	}
	
	//�¿�����
	if(flag) dfs(gr+1,0,0,cnt);	
}

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++) cin >> p[i];
	
	dfs(1,0,0,0);
	
	cout << ans;
	
	return 0;
}
