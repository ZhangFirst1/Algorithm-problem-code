//���串��
//���� N �������� [ai,bi] �Լ�һ���߶����� [s,t]������ѡ�����ٵ����䣬��ָ���߶�������ȫ���ǡ�
//�������������������޷���ȫ��������� -1
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
const int N = 100010;

struct Range{
	int l,r;
	bool operator< (const Range &W)const{
		return l < W.l;
	}
}range[N];

int main(){
	int st,ed;
	cin >> st >> ed;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int l,r;
		cin >> l >> r;
		range[i] = {l,r};
	}
	sort(range+1, range+1+n);
	
	int res = 0;
	bool flag = false;
	//����˵㶼С��st������£�ȡ�Ҷ˵���������
	for(int i=1;i<=n;i++){
		int j = i, r = -2e9;
		while(j <= n && range[j].l <= st){
			r = max(r, range[j].r);
			j++;
		}
		if(r < st){ //������䶼С��st���޷�����
			break;
		}
		res++; //ʹ�ø����串��
		if(r >= ed){ //�����Ѿ�����ed���Ѿ����Ը��ǣ�����ѭ��
			flag = true;
			break;
		}
		
		st = r; //�������
		i = j - 1; //ת������ǰ����(ѭ������i++,���Ե���j-1)
	}
	
	if(!flag) cout << -1;
	else cout << res;
	return 0;
}
