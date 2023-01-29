//sg������ʾ�����ڼ����е���С��Ԫ��
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>

using namespace std;
const int N = 10010;

int s[N], f[N];
int n,m;

int sg(int x){
    if(f[x] != -1) return f[x]; //���仯����
    set<int> S;		//��ŵ�ǰ�������п��Ե���ľ���
    
    for(int i=1;i<=n;i++){
        int t = s[i];
        if(x >= t) S.insert(sg(x-t));
    }
    
    for(int i=0; ;i++)	//��ǰ�����в����ڵ���С�Ǹ�����
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
    if(res) cout << "Yes" << endl; //sg�����ֵ��Ϊ0��Ϊ��ʤ̬
    else cout << "No" << endl;	   //������Ϊ�ذ�̬
    
    return 0;
}
