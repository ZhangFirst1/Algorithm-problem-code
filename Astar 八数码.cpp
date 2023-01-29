/*A*�㷨
1.�ó���ͷ����չԪ��
2.������չԪ�ص��յ�ľ���
3.����չ���Ԫ�ؽ��д�С�������򣬲���С����Ϊ��ͷ

������https://www.acwing.com/solution/content/35528/
ps  1.���ƾ���ҪС����ʵ����
	2.��Ŀ��֤�н⣬����O��logn��
	3.�����Ϊ����ʱһ���޽�
	4.�յ���Ӻ�ȷ����
*/

//��ʱ�� ����ɾȥ����ע��
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_map>

#define x first
#define y second

using namespace std;
typedef pair<int,string> PIS;

int f(string m){	//���ƺ���
	int dt = 0;
	for(int i=0;i<9;i++){
		if(m[i] != 'x'){
			int t = m[i] - '1'; //��Ӧ�±�
			dt = dt + abs(i/3 - t/3) + abs(i%3 - t%3); //�����پ��루���벽����Ϊ��
		}
	}
	return dt;
}

string bfs(string start){
	string end = "12345678x";
	
	unordered_map<string,int> d; //�洢����
	priority_queue<PIS, vector<PIS>, greater<PIS> > heap; // ��Ԫ�ع����յ�����С��������
	unordered_map<string, pair<string,char> > pre; //�洢��һ״̬
	
	heap.push({f(start), start}); //�������
	d[start] = 0; //��ʼ��������
	
	char oper[] = "udlr";
	int dy[4] = {-1,0,0,1}; int dx[4] = {0,-1,1,0};
	
	while(heap.size()){
		auto t = heap.top();
		heap.pop();
		string state = t.y; //��¼
		
		if(t.y == end) break; //�յ�������˳�
		
		int aa,bb; //��¼x��λ��
		for(int i=0;i<=8;i++){
			if(state[i] == 'X'){
				aa = i / 3,bb = i % 3;
				break;
			}
		}
		
		string init = state;
		for(int i=0;i<4;i++){
			int a = aa + dx[i]; int b = bb + dy[i];
			if(a < 0 || a >=3 || b < 0 || b >= 3) continue;
			swap(state[a*3+b],state[aa*3+bb]); //�����±�λ��
			if(!d.count(state)|| d[state] > d[init] + 1){ //û�б���¼��С�ڼ�¼ֵ
				d[state] = d[init] + 1;
				heap.push({f(state) + d[state], state}); //�������
				pre[state] = {init, oper[i]};// ���������״̬ת����������¼����
			}
			state = init; //��ԭ
		}	
	}
	
	string ans;
	while(end != start){
		ans += pre[end].y;
		end = pre[end].x;
	}
	reverse(ans.begin(),ans.end());
	
	return ans;
	
}


int main(){
	string start,xx;
	for(int i=0;i<9;i++){
		char c;
		cin >> c;
		start += c;
		if(c != 'x') xx += c;
	}
	
	int res = 0; //ͳ�������
	for(int i=0;i<8;i++)
		for(int j=i+1;j<8;j++)
			if(xx[i] > xx[j]) res++;
	
	if(res%2) cout << "unsolvable" << endl;
	else cout << bfs(start) << endl;
	
	
	return 0;
}
