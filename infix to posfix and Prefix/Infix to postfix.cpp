#include<iostream>
#include<stack>
using namespace std;
void postfix(char a[])
{
	stack<char> s;
	char t,ch;
	for (int i = 0; a[i] != '\0'; i++)
	{
		ch = a[i];
		if (ch == '^' || ch == '%' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
			s.push(ch);
		else if (ch == ')')
		{
			t = s.top();
			s.pop();
			cout << t;
		}
		else if (isalpha(ch) || isdigit(ch))
			cout << ch;
	}
}
int main()
{
	char a[100];
	cout << "\n Enter the infix expression with braces \t";
	cin >> a;
	postfix(a);
	cout << endl;
	system("pause");
	return 0;
}
