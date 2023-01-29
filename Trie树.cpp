//trie��
//I x�򼯺ϲ���һ���ַ���(Сд)
//Q xѯ��һ���ַ����ڼ����г����˶��ٴ�
//5
//I abc
//Q abc
//Q ab
//I ab
//Q ab
//out 1 0 1
#include<iostream>

using namespace std;
const int N = 100010;

char str[N];
int son[N][26];	//26��ʾСдӢ����ĸ
int cnt[N]; //�Ե�ǰ���β�ĵ����ж��ٸ�
int idx;	//�±���0�ĵ㣬���Ǹ��ڵ㣬���ǿսڵ㣬idx��ʾ�ڵ���

void Insert(char str[]){
	int p = 0;
	for(int i=0;str[i];i++){
		int u = str[i] - 'a';
		if(!son[p][u]) son[p][u] = ++idx; //����ڵ�p������u��������򴴽�
		p = son[p][u];	//ʹ��pָ�롱ָ����һ���ڵ�λ��
	}
	cnt[p]++;	//�Ըýڵ��β�ĵ���+1
}

int query(char str[]){
	int p = 0;
	for(int i=0;str[i];i++){
		int u = str[i] - 'a';
		if(!son[p][u]) return 0;
		p = son[p][u];
	}
	return cnt[p];
}

int main(){
	int n;
	cin >> n;
	while(n--){
		char op[2];
		scanf("%s%s",op,str);
		if(op[0] == 'I') Insert(str);
		else cout << query(str) << endl;
	}	
	
	return 0;
}
