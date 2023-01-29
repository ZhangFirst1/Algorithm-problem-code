// ���鼯
// ��sizeȥά��ÿ����ͨ��ĸ�����d[x]��ʾx����ǰ���ڽ��ľ��룬d[x]��findһ�κ�����
// ÿ�ΰ�size�ӵ�pa�ϣ���������pa��ͨ���ϵĵ��d[i],֮�����ʱ����������size

#include <iostream>

using namespace std;

const int N = 30010;

int p[N], d[N], size[N];
int a, b;

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]); // �ݹ鵽��
        d[x] += d[p[x]]; // �ӵ����أ����¾���
        p[x] = root; // ѹ��·��
    }
    return p[x];
}


int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < N; i ++) {
        p[i] = i;
        size[i] = 1;
        d[i] = 0;
    }

    while(T --) {
        char op[2]; // ��scanf�������ַ�������д��
        scanf("%s%d%d", op, &a, &b);

        if (op[0] == 'M') {
            int pa = find(a), pb = find(b);
            d[pa] += size[pb]; // ��size�ӵ�pa��㼴�ɣ�����ԭpa��ͨ���ϵľ�����֮��findʱ����������size
            size[pb] += size[pa];
            p[pa] = pb;
        } else {
            int pa = find(a), pb = find(b);
            // ����findһ��,���ܰ�d[a],d[b]���µ�����
            if (pa != pb) cout << "-1" << endl;
            else {
                cout << max(abs(d[a] - d[b]) - 1, 0) << endl;
            }
        }
    }
	return 0;
}


