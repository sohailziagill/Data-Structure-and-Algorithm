#include<iostream>
#include<string>
#include<stack>
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

int main()
{
	stack<char> mystack; //For infix to postfix
	int mytop,m,i,choice ;
	char token , infix[MAX],postfix[MAX];
do{	
	mytop=-1;
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
	       if(mytop == -1 || token == '(')
		     {
		   	   mystack.push(token); mytop++;
		     }		     
		   else if(token == ')') 
		     {
		    	do{
				    postfix[m++] = mystack.top();
				    mystack.pop(); mytop--;
					if(mytop == -1) //very imp check if not than while loop doesn't break
				   break;				    
				  }while(mystack.top() != '(');
				  mystack.pop(); //remove ')'
				  mytop--;
			 }  
		   else if( (mystack.top() != '(') && (priorityTable(mystack.top()) <= priorityTable(token)) )	
		     {
		    	do
				{
				  postfix[m++] = mystack.top();
				  mystack.pop(); mytop--;
				  if(mytop == -1) //very imp check if not than while loop doesn't break
				   break; 	
				}while( (mystack.top() != '(') && (priorityTable(mystack.top()) <= priorityTable(token)));
			   mystack.push(token); mytop++;			   	
		     }
		   else
		     {  
		        mystack.push(token); mytop++;
			 }
        }	
     i++;
	}
    while(mytop != -1)
    {
    	postfix[m++] = mystack.top();
    	mystack.pop();
    	mytop--;    	
	} 
	postfix[m] = '\0';	
    cout<<postfix<<endl;
    
    do{	
        cout<<"Press 1 for continue 0 for exit : ";
        cin>>choice;
        if(choice !=0 && choice !=1)
          cout<<"Error"<<endl;
      }while(choice !=0 && choice !=1);
}while(choice);
	system("pause");
	return 0;
}
