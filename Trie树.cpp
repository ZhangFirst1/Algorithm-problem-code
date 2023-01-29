//trie树
//I x向集合插入一个字符串(小写)
//Q x询问一个字符串在集合中出现了多少次
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
int son[N][26];	//26表示小写英文字母
int cnt[N]; //以当前点结尾的单词有多少个
int idx;	//下标是0的点，既是根节点，又是空节点，idx表示节点编号

void Insert(char str[]){
	int p = 0;
	for(int i=0;str[i];i++){
		int u = str[i] - 'a';
		if(!son[p][u]) son[p][u] = ++idx; //如果节点p不存在u这个儿子则创建
		p = son[p][u];	//使“p指针”指向下一个节点位置
	}
	cnt[p]++;	//以该节点结尾的单词+1
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
