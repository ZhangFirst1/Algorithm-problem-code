//˫�򱼸����� ������̲����Ż�
//�ַ��任
//https://www.acwing.com/problem/content/192/
#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>

using namespace std;
const int N = 6;

string a[N],b[N];
int n;

int extend(queue<string>& q,unordered_map<string,int>& da,unordered_map<string,int>& db,string a[],string b[]){
	string t = q.front();
	q.pop();
	
	for(unsigned int i=0;i<t.size();i++){ //ö���ַ���
		for(int j=0;j<n;j++){	//ö�ٱ任����
			if(t.substr(i,a[j].size()) == a[j]){
			 // �任֮��Ľ��state:ǰ�治��Ĳ���+ �仯�Ĳ��� + ���治��Ĳ���
			// ����abcd �����ݹ���abc--> xu����� xud�������state����xud
				string state = t.substr(0,i) + b[j] + t.substr(i+a[j].size());
				 // state״̬�Ƿ��䵽b����ȥ�����������ʦ��������С����
				if(db.count(state)) return da[t] + 1 + db[state];
				//�����չ���������
				if(da.count(state)) continue;
				da[state] = da[t] + 1; //����+1
				q.push(state);
			}
		}
	}
	return 11;
}

int bfs(string A,string B){
	if(A == B) return 0; //����
	
	queue<string> qa,qb; //��������Ķ���
	unordered_map<string,int> da,db; //ÿ��״̬��������յ����
	
	qa.push(A); qb.push(B);
	da[A] = 0;	db[B] = 0;
	
	//qa��qb����ֵ��˵��������չ�������ཻ
	while(qa.size() && qb.size()){
		int t; //��¼��С����
		//�Ӷ��г��Ƚ�С��һ�ӿ�ʼ��չ
		if(qa.size() <= qb.size())
			t = extend(qa,da,db,a,b);
		else t = extend(qb,db,da,b,a); //�Ӻ���ǰʱ����ҲӦ������
		
		if(t <= 10) return t;
	}
	return 11; //����ͨ����С��������10
}

int main(){
	string A,B;
	cin >> A >> B;
	
	while(cin >> a[n] >> b[n]) n++; //�������
	
	int step = bfs(A,B);
	if(step > 10) cout << "NO ANSWER!";
	else cout << step << endl;
	
	return 0;
}
