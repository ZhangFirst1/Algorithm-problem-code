#include<iostream>

using namespace std;
const int N = 110;

int a[N];
int n,m;
bool st[N];

void dfs(int u,int s){
    if(u + n - s < m) return; //¼ôÖ¦¶ù
    
    if(u > m){
        for(int i=1;i<=m;i++)
            printf("%d ",a[i]);
        cout << endl;
        return;
    }
    
    for(int i=s;i<=n;i++){
        if(!st[i]){
            a[u] = i;
            st[i] = true;
            dfs(u+1,i+1);
            st[i] = false;
        }
    }
    
    
}

int main(){
    cin >> n >> m;
    
    dfs(1,1);
    return 0;
}
