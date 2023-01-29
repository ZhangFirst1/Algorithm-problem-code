//ľ��
//����������Ϊ���飬��֤�������ֺ���ȣ�����С��
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 70;

int n,sum,len;
int w[N];
bool st[N];

//u��ʾ�ڼ�����ľ����s��ʾ��ǰľ�����ȣ�start��ʾ��u��ö��λ��
bool dfs(int u,int s,int start){
	if(u * len == sum) return true; //����ܳ���Ϊsum�򷵻�
	if(s == len) return dfs(u+1,0,0); //true����ʱҪ����
	
	for(int i=start;i < n;i++){
		if(st[i]) continue;
		if(s + w[i] > len) continue; //�����Լ�֦
		
		st[i] = true;
		if(dfs(u, s+w[i], i + 1)) return true;
		st[i] = false; //�ָ��ֳ�
		
		if(!s || w[i] + s == len) return false; //�����һ�������һ��ʧ�ܣ���һ��ʧ�� 
		
		int j = i; //���iʧ�ܣ����i����һ����Ҳ��ʧ��
		while(j <= n && w[j] == w[i]) j++;
		i = j- 1;
	}
	
	return false;
}

int main(){
	while(cin >> n , n){
		memset(st,0,sizeof st);
		sum = 0, len = 1; 
		
		for(int i=0;i<n;i++){
			cin >> w[i];
			sum += w[i];
		}
		
		sort(w,w+n); //�Ż�˳���֦
		reverse(w,w+n);
		
		while(1){ //ö��ľ������
			if(sum % len == 0 && dfs(0,0,0)){ //�������ܷ֣���֦1
				cout << len << endl;
				break;
			}
			len++;
		}
	}
	
	return 0;
}
