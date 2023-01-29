//kmp
#include<iostream>
#include<cstring>

using namespace std;
const int N = 1000010;

int ne[N];
char s[N],f[N];

void getNext(char *a){
	int len = strlen(a);
	int i = 0, j = -1;
	ne[0] = -1;
	while(i < len){
		if(j != -1 || a[i] == a[j])
			ne[++i] = ++j;
		else j = ne[j];
	}
}

int KMP(char *a,char *b){
	int lena = strlen(a);
	int lenb = strlen(b);
	int i = 0,j = 0;
	while(i < lena && j < lenb){
		if(j == -1 || a[i] == b[j]){
			i++;	j++;
		}else{
			j = ne[j];
		}
	}
	if(j == lenb) return i-j+1;
	else return -1;	
}

int main(){
	scanf("%s",s);
	scanf("%s",f);
	getNext(f);
	cout << KMP(s,f);
	
	return 0;
}
