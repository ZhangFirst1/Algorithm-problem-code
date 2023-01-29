#include<iostream>
#include<cstring>

using namespace std;
const int N = 1010;

int v[N], w[N], f[N][N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> w[i] >> v[i];
    
    for(int i=n;i>=1;i--){
        for(int j=0;j<=m;j++){
            f[i][j] = f[i+1][j];
            if(j >= w[i]){
                f[i][j] = max(f[i][j], f[i+1][j-w[i]]+v[i]);
            }
        }
    }
    
    int t = m;
    for(int i=1;i<=n;i++){
        if(i == n && t >= w[i]){
            cout << i << ' ';
            break;
        }
        if(t <= 0) break;
        if(t - w[i] >= 0 && f[i][t] == f[i+1][t - w[i]]+v[i]){
            cout << i << ' ';
            t -= w[i];
        }
    }
    
    return 0;
}
