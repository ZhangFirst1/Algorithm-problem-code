//���ݱհ�
//https://www.acwing.com/problem/content/description/345/
//1.ì��d[i][i] = 1;
//2.Ψһȷ�� i != j, d(i,j)��d(j,i)����һ����1
//3.˳��Ψһ������ִ��
//�����ҵ�һ��С����������
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 27;

bool g[N][N],d[N][N]; //d[i][j] ��ʾ i < j
bool st[N];
int n,m;

void floyd(){
	memcpy(d,g,sizeof d);
	
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(!d[i][j]) d[i][j] = d[i][k] & d[k][j];
				//d[i][j] |= d[i][k] & d[k][j]
}

int check(){
	//0����ȷ�� 1��ȷ����˳�� 2��ì��
	for(int i=0;i<n;i++)
		if(d[i][i]) return 2; //d[i][i] = 1��ʾ��ì��
	
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(!d[i][j] && !d[j][i]) //��d[i][j],d[j][i]��Ϊ0�����ϵ����ȷ��
				return 0; 
	
	return 1;
}

char get_min(){ //ÿ��ȡ����С��ֵ
	for(int i=0;i<n;i++){
		if(!st[i]){ //�ж���û���κ�һ��Ԫ��С�ڵ�ǰԪ��
			bool flag = true;
			for(int j=0;j<n;j++)
				if(!st[j] && d[j][i]){ //����һ��û�������С��i��Ԫ��
					flag = false;
					break;
				}
			if(flag){
				st[i] = true;
				return 'A' + i;
			}
		}
	}	
}

int main()
{
    while(cin >> n >> m, n || m)
    {
        memset(g, 0, sizeof g);
        int type = 0, t; // t ��¼�ִ�  type��¼�жϳ������ı�־
        for(int i = 1; i <= m; i ++)
        {
            char str[5];
            cin >> str;
            int a = str[0] - 'A', b = str[2] - 'A';
            
			if(a == b){ //ע������ X<X �������
			    t = i;
			    type = 2;
				break;
			}
			
            if(!type) //��ǰ����Բ�ȷ��
            {
                g[a][b] = 1;
                floyd();
                type = check();
                if(type) t = i; //��¼��ǰ��������
            }
        }

        if(type == 0) puts("Sorted sequence cannot be determined.");
        else if(type == 2) printf("Inconsistency found after %d relations.\n", t);
        else 
        {
            memset(st, 0, sizeof st);
            printf("Sorted sequence determined after %d relations: ", t);
            for(int i = 0; i < n; i ++) printf("%c", get_min());
            cout << "." << endl;
        }
    }
    return 0;
}
