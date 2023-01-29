//���ʽ��ֵ
//ջ��������ͼ�����ջ������������ȼ��Ƚϣ�
//���ջ������������ȼ��ͣ��������ֱ����ջ
//���ջ������������ȼ��ߣ��ȳ�ջ���㣬�����������ջ(��ͬʱ��Ϊջ�����ȼ��ߣ��ȼ���)
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

stack<int> num;
stack<char> op;

//���ȼ���
unordered_map<char, int> h{ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };


void eval()//��ֵ
{
    int a = num.top();
    num.pop();

    int b = num.top();
    num.pop();

    char p = op.top();
    op.pop();

    int r = 0;

    //������
    if (p == '+') r = b + a;
    if (p == '-') r = b - a;
    if (p == '*') r = b * a;
    if (p == '/') r = b / a;

    num.push(r);//�����ջ
}

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))//������ջ
        {
            int x = 0, j = i;//��������
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + s[j] - '0';
                j++;
            }
            num.push(x);//������ջ
            i = j - 1;
        }
        //�����������ȼ���ֱ����ջ
        else if (s[i] == '(')//��������ջ
        {
            op.push(s[i]);
        }
        //���������ż������������
        else if (s[i] == ')')//������
        {
            while(op.top() != '(')//һֱ���㵽������
                eval();
            op.pop();//�����ų�ջ
        }
        else
        {
            while (op.size() && h[op.top()] >= h[s[i]])//����ջ��������ȼ��ͣ����ȼ���
                eval();
            op.push(s[i]);//��������ջ
        }
    }
    while (op.size()) eval();//ʣ��Ľ��м���
    cout << num.top();//������
    return 0;
}
