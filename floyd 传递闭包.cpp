//传递闭包
//https://www.acwing.com/problem/content/description/345/
//1.矛盾d[i][i] = 1;
//2.唯一确定 i != j, d(i,j)与d(j,i)必有一个是1
//3.顺序不唯一，继续执行
//排序：找到一个小于其他所有
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 27;

bool g[N][N],d[N][N]; //d[i][j] 表示 i < j
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
	//0不能确定 1有确定的顺序 2有矛盾
	for(int i=0;i<n;i++)
		if(d[i][i]) return 2; //d[i][i] = 1表示有矛盾
	
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(!d[i][j] && !d[j][i]) //若d[i][j],d[j][i]都为0，则关系不能确定
				return 0; 
	
	return 1;
}

char get_min(){ //每次取出最小的值
	for(int i=0;i<n;i++){
		if(!st[i]){ //判断有没有任何一个元素小于当前元素
			bool flag = true;
			for(int j=0;j<n;j++)
				if(!st[j] && d[j][i]){ //存在一个没有输出的小于i的元素
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
        int type = 0, t; // t 记录轮次  type记录判断出来与否的标志
        for(int i = 1; i <= m; i ++)
        {
            char str[5];
            cin >> str;
            int a = str[0] - 'A', b = str[2] - 'A';
            
			if(a == b){ //注意特判 X<X 的情况。
			    t = i;
			    type = 2;
				break;
			}
			
            if(!type) //当前结果仍不确定
            {
                g[a][b] = 1;
                floyd();
                type = check();
                if(type) t = i; //记录当前迭代次数
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
