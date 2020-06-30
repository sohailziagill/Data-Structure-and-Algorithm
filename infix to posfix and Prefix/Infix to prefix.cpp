#include<iostream> 
using namespace std;
#define MAX 1000
class stack {
	int top;

public:
	int arr[MAX]; // Maximum size of Stack 

	stack()
	{
		top = -1;
	}
	bool push(int x);
	int pop();
	int gettop();
	bool isEmpty();
};

bool stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		arr[++top] = x;
		return true;
	}
}

int stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = arr[top--];
		return x;
	}
}
int stack::gettop()
{
	if (top < 0) {

		return 0;
	}
	else {
		int x = arr[top];
		return x;
	}
}

bool stack::isEmpty()
{
	return (top < 0);
}
int findPresedence(char ch)
{
	switch (ch)
	{
	case'+':
	case'-':
		return 1;
	case'*':
	case'/':
		return 2;
	default:
		return 0;
	}
}
int main()
{
	char infix[100], infix1[100], postfix[100], prefix[100], ch, token;
	int i = 0, j = 0;
	stack s;
	cout << "\n Enter the infix expression \t";
	cin >> infix1;
	int length = 0;
	while (infix1[length] != '\0')
		length++;
	length = length - 1;
	for (j = length; j >= 0; j--)
	{
		/*   First chang the brackets () to )(    */
		if (infix1[j] == '(')
			infix1[j] = ')';
		else if (infix1[j] == ')')
			infix1[j] = '(';
		/*    Reverse the infix expression       */
		infix[i++] = infix1[j];
	}
	infix[i] = '\0';
	/* Infix to postfix conversion   */
	i = 0;
	j = 0;
	while (infix[i] != '\0')
	{
		if (isalpha(infix[i]) || isdigit(infix[i]))
			postfix[j++] = infix[i];
		/* For opening braces     */
		else
		{
			ch = infix[i];
			if (ch == '(')
				s.push(ch);
			/*   For the closing braces  */
			else if (ch == ')')
			{
				while (token = s.gettop())
				{
					if (token != '(')
					{

						postfix[j++] = token;
						s.pop();
					}
					else
						break;
				}
				s.pop();
			}
			else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				while (findPresedence(s.gettop()) >= findPresedence(ch))
				{
					if (findPresedence(s.gettop()) >= findPresedence(ch))
					{
						postfix[j++] = s.gettop();
						s.pop();
					}
					else
						break;
				}
				s.push(ch);
			}

		}

		i++;
	}
	postfix[j] = '\0';
	/* Inverse postfix to make prefix */
	length = 0;
	while (postfix[length] != '\0')
		length++;
	length = length - 1;
	i = 0;
	j = 0;
	for (j = length; j >= 0; j--)
	{
		/*   First chang the brackets () to )(    */
		if (postfix[j] == '(')
			postfix[j] = ')';
		else if (postfix[j] == ')')
			postfix[j] = '(';
		/*    Reverse the postfix expression       */
		prefix[i++] = postfix[j];
	}
	prefix[i] = '\0';
	cout << "\n The prefix expression  is " << prefix;
	cout << endl;
	system("pause");
	return 0;
}
