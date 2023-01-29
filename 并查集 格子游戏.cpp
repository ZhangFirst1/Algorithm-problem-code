#include<iostream>
#include<algorithm>

using namespace std;
const int N = 510000;

int fa[N],n,m;

int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int get(int x,int y){
    return x * n + y;
}

int main(){
    int res = 0;
    cin >> n >> m;
    for(int i=0;i<n*n;i++) fa[i] = i;
    
    for(int i=1;i<=m;i++){
        int x,y;
        char op;
        cin >> x >> y >> op;
        x--;    y--; //将二维坐标变为一维，从0开始xn+y;
        int a = get(x,y);
        int b;
        if(op == 'D') b = get(x+1,y);
        else b = get(x,y+1);
        
        int pa = find(a);
        int pb = find(b);
        if(pa == pb){
            res = i;
            break;
        }
        fa[pa] = pb;
    }
    
    if(!res) cout << "draw";
    else cout << res;
    return 0;
}
