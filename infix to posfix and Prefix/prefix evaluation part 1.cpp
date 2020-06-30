#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
#define MAX 1000

int calc(int a, int b, char ch)
{
	switch (ch)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	case '^':
		return pow(a, b);
	}
}

int main()
{
	int a, b,i=0,j=0;
	float result;
	char ch,prefix[MAX];
	stack<int> s;
	cout << "\n Enter the postfix expression \t";
	cin >> prefix;
	while (prefix[i] != '\0')
	i++;
	i=i-1;
	for(j=i;j>=0;j--)
	{
	
		if (isalpha(prefix[j]))
		{
			cout << "\n Error ";
			exit(-1);
		}
		else if (isdigit(prefix[j]))
		{
			// For ascii code.
			s.push(static_cast<int>(prefix[j]) - 48);
			
		}
		/* Operators only */
		else
		{
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			s.push(calc(a, b, prefix[j]));

		}
		i++;
	}
	result = s.top();
	s.pop();
	cout << "\n The result is " << result;
    cout << endl;
	system("pause");
	return 0;
}
