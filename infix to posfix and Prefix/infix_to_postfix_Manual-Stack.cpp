#include<iostream>
#include<string>
#define MAX 100
using namespace std;
int priorityTable(char ch)
{
	switch(ch)
	{
	  case '^':
	  return 2;
	  break;
	  case '*':
	  return 3;
	  break;
	  case '/':
	  return 3;
	  break;
	  case '+':
	  return 4;
	  break;
	  case '-':
	  return 4;
	  break;
	  
	  default:
	  return 0;	
	}
}
class Stack {
//	int top;
   	int a[MAX];
public:
 // Maximum size of Stack 
    int top;
	Stack() { top = -1; }
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		return true;
	}
}

int Stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}
int Stack::peek()
{
	if (top < 0) {

		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

////////////////////////////////////////////////////MAIN///////////////////////////////////////////////
int main()
{
	Stack s;
	int m , i , choice;
	char infix[MAX] , postfix[MAX] , token;
	
do{
	m=0,i=0;
	cout<<"Enter Expression: ";
	cin>>infix;
	
	while(infix[i] != '\0')
	{
	  token = infix[i];
	  if(isalpha(token) || isdigit(token))
	    postfix[m++] = token;
	  else
	    {
		  if(s.top == -1 || token == '(')
		   s.push(token);
		  else if(token == ')') 
		    {
		    	do{
				    postfix[m++] = s.pop();
					if(s.top == -1) //very imp check if not than while loop doesn't break
				   break;				    
				  }while(s.peek() != '(');
				  s.pop();
			}
		  else if( (s.peek() != '(') && (priorityTable(s.peek()) <= priorityTable(token)) )	
		    {
		    	do
				{
				  postfix[m++] = s.pop();
				  if(s.top == -1) //very imp check if not than while loop doesn't break
				   break; 	
				}while( (s.peek() != '(') && (priorityTable(s.peek()) <= priorityTable(token)));
			 s.push(token);	
			}
		  else
		     s.push(token);	
		} 
	 i++;	
	}
	while(s.top != -1)
	 postfix[m++] = s.pop();
	
	postfix[m] = '\0';
	cout<<postfix<<endl;
	do{
	
	cout<<"Press 1 for coninue 0 for exit ";
	cin>>choice;
	if(choice != 0 && choice != 1)
	cout<<"Error\n";
    }while(choice != 0 && choice != 1);
}while(choice);
	system("pause");
	return 0;
}
