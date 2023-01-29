//表达式求值
//栈顶运算符和即将入栈的运算符的优先级比较：
//如果栈顶的运算符优先级低，新运算符直接入栈
//如果栈顶的运算符优先级高，先出栈计算，新运算符再入栈(相同时认为栈顶优先级高，先计算)
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

stack<int> num;
stack<char> op;

//优先级表
unordered_map<char, int> h{ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };


void eval()//求值
{
    int a = num.top();
    num.pop();

    int b = num.top();
    num.pop();

    char p = op.top();
    op.pop();

    int r = 0;

    //计算结果
    if (p == '+') r = b + a;
    if (p == '-') r = b - a;
    if (p == '*') r = b * a;
    if (p == '/') r = b / a;

    num.push(r);//结果入栈
}

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))//数字入栈
        {
            int x = 0, j = i;//计算数字
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + s[j] - '0';
                j++;
            }
            num.push(x);//数字入栈
            i = j - 1;
        }
        //左括号无优先级，直接入栈
        else if (s[i] == '(')//左括号入栈
        {
            op.push(s[i]);
        }
        //遇到右括号计算括号里面的
        else if (s[i] == ')')//右括号
        {
            while(op.top() != '(')//一直计算到左括号
                eval();
            op.pop();//左括号出栈
        }
        else
        {
            while (op.size() && h[op.top()] >= h[s[i]])//待入栈运算符优先级低，则先计算
                eval();
            op.push(s[i]);//操作符入栈
        }
    }
    while (op.size()) eval();//剩余的进行计算
    cout << num.top();//输出结果
    return 0;
}
