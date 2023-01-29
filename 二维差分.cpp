//二维差分
//输入一个 n 行 m 列的整数矩阵，再输入 q 个操作，每个操作包含五个整数 x1,y1,x2,y2,c，
//其中 (x1,y1) 和 (x2,y2) 表示一个子矩阵的左上角坐标和右下角坐标。
//每个操作都要将选中的子矩阵中的每个元素的值加上 c。
#include<iostream>

using namespace std;
const int N = 1e3+10;

int a[N][N],b[N][N];

void Insert(int x1,int y1,int x2,int y2,int c){
	b[x1][y1] += c;
	b[x1][y2+1] -= c;
	b[x2+1][y1] -= c;
	b[x2+1][y2+1] += c;
}

int main(){
	int n,m,q;
	cin >> n >> m >> q;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) 
			scanf("%d",&a[i][j]);
			
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			Insert(i,j,i,j,a[i][j]);	//构建差分数组
	
	while(q--){
		int x1,y1,x2,y2,c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		Insert(x1,y1,x2,y2,c);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j] = b[i-1][j] + b[i][j-1] + b[i][j] - b[i-1][j-1]; //数组b是a的差分，可直接用数组b构造差分
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
