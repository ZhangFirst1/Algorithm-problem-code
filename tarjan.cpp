//https://www.acwing.com/solution/content/20678/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010, M = 50010;

int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, Size[N];//ÿ��ǿ��ͨ�ֵĽڵ����
int dout[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void tarjan(int u)
{
    //u��ʱ���
    dfn[u] = low[u] = ++timestamp;
    //�ѵ�ǰ��ӵ�ջ��  ��ǰ����ջ��
    stk[++top] = u,in_stk[u] = true;

    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!dfn[j])//j��δ��������
        {
            tarjan(j);//����dfs ����j
            //jҲ����ڷ���ߵ����u���ߵĲ�,������j�ܵ�����Сdfn��(��ߵ�)����u�ܴﵽ��(��Сdfn��)��ߵ�
            low[u] = min(low[u],low[j]);
        }
        //j����ջ��  ˵����û��ջ ��dfs��ȵ�ǰ��uС��
        //���� 1Ҫô�Ǻ���(��߷�֧�ĵ�)
        //         o
        //        / \
        //       j �� u    
        //     2Ҫô��u�����ڽڵ�
        //         j
        //      �J/ 
        //       u    
        //    �������u��dfs�򶼱�j�� ������dfn[j]����low[u]
        else if(in_stk[j])
        {
            low[u] = min(low[u],dfn[j]);//ֱ����j��ʱ�������u
        }
        //ջ����ǰδ�������ǿ��ͨ���������е�
    }
    // ?
    // ����һ��Ϊʲôtarjan������dfs��
    // ������������ߵĸ��ڵ�fa
    // ���漸���� fa�Ķ��ӽڵ�j���Ѿ������ǵĵݹ�������������9�д���
    // ���оͰ��� ++scc_cnt 
    // ���ݹ���ݵ��߲�ڵ��ʱ�� �ӽڵ��scc��������
    // �ڵ�Խ�� scc_idԽ��
    // �����Ǻ���������·dp��ʱ���ֵôӸ��߲�����
    // ���Ե�for(int i=scc_cnt(���ڵ����ڵ�scc);i;i--)��ʼ

    // ���Ե�������u�������ܵ��ĵ�� ����u����ܵ��ĵ����Լ�
    // 1 ��uΪǿ��ͨ�����е���ߵ�,����uΪ������°Ѹ�ǿ��ͨ�������нڵ㶼�ҳ���
    // 2 Ҫô����û�л�,����һ�����������µĵ�
    if(dfn[u]==low[u])
    {
        int y;
        ++scc_cnt;//ǿ��ͨ��������+1
        do
        {
            y = stk[top--];//ȡջ��Ԫ��y
            in_stk[y] = false;//��y������ջ��
            id[y] = scc_cnt;
            Size[scc_cnt] ++;//��scc_cnt����ͨ�����+1
        }while(y!=u);
        //1 ��Ϊջ��Խ�ߵ�Ԫ�ص�dfs��Խ��,��ô����ֻ��Ҫ��dfs���u�����Щpop��u
        //����Ϊ���ջ�������ϻص�u ���Ե�y==u     
        //��˵����u���ڵ�����ǿ��ͨ�����������id
        //           ��  u
        //          /  /
        //         /  ne1
        //         �� ne2
        //      ��Ϊne2����u�ܵ���dfs��������,Ҳ���Ǵ�ʱ��ջ��
        //      ��ô���Ǿ���һpop��ne2��ne1
        //2 Ҫô������һ��û�л��ĵ� ��õ㵥���һ����ͨ����
    }
}

int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
    }

    for (int i = 1; i <= n; i ++ )
        if (!dfn[i])
            tarjan(i);
    //ͳ����ͼ�е�ĳ��� 
    for (int i = 1;i <= n; i ++ )
        for (int j = h[i];j!=-1; j = ne[j])
        {
            int k = e[j];
            int a = id[i], b = id[k];//a,b��Ϊһ����ͨ����
            if (a != b) dout[a] ++ ;//a����+1  dout[a] += i��k
        }
    int zeros = 0, sum = 0;//sum ������г���Ϊ0��ǿ��ͨ�����ĵ������
    for (int i = 1; i <= scc_cnt; i ++ )
        if (!dout[i])//�����i��ǿ��ͨ��������==0
        {
            zeros ++ ;
            sum += Size[i];//����ϵ�i��ǿ��ͨ�����ĵ�ĸ���
            if (zeros > 1)//�����k>1������Ϊ0�� ������k-1ͷţ��������ţ��ӭ
            {
                sum = 0;
                break;
            }
        }

    cout << sum;
    return 0;
}
