//sg函数表示不存在集合中的最小的元素
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>

using namespace std;
const int N = 10010;

int s[N], f[N];
int n,m;

int sg(int x){
    if(f[x] != -1) return f[x]; //记忆化搜索
    set<int> S;		//存放当前局面所有可以到达的局面
    
    for(int i=1;i<=n;i++){
        int t = s[i];
        if(x >= t) S.insert(sg(x-t));
    }
    
    for(int i=0; ;i++)	//当前集合中不存在的最小非负整数
        if(!S.count(i))
            return f[x] = i;
    
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> s[i];
    cin >> m;
    int res = 0;
    
    memset(f, -1 ,sizeof f);
    while(m--){
        int x;
        cin >> x;
        res ^= sg(x);
    }
    if(res) cout << "Yes" << endl; //sg的异或值不为0则为必胜态
    else cout << "No" << endl;	   //否则则为必败态
    
    return 0;
}
