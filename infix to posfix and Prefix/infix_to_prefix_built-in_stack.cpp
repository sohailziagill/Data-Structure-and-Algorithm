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
	int monkey , choice;
	stack<char> mystack; //For infix to postfix
	int mytop,m,i ;
	char token , infix[MAX],postfix[MAX] , infix1[MAX];
	
do{
	
	monkey=0;
	mytop=-1;
	m=0,i=0;
	cout<<"Enter Expression: ";
	cin>>infix;
	
	while(infix[monkey] != '\0' ) //get the monkey
     monkey++;
    for(int x=monkey-1;x>=0;x--)
	  {
	     if(infix[x] == '(') //first chang the brackets () to )(
	        infix[x] = ')';
	     else if(infix[x] == ')')
		    infix[x] = '(';
		    
		 infix1[i++] = infix[x]; //reverse infix		 	  
	  } 
	 infix1[i] = '\0';
	 cout<<"\n The Updated  reverse string is "<<infix1;
    //cout<<infix1<<endl;
	m=0,i=0;
	while(infix1[i] != '\0') //infix to postfix
	{
	  token = infix1[i];
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
    while(mytop != -1) //do the stack empty
    {
    	postfix[m++] = mystack.top();
    	mystack.pop();
    	mytop--;    	
	} 
	postfix[m] = '\0'; 
	//cout<<postfix<<endl;
	
	i = monkey = 0;
	while(postfix[monkey] != '\0' ) //get the monkey
     monkey++;
     
    for(int x=monkey-1;x>=0;x--)
	  {	     	    
		 infix1[i] = postfix[x];
		 i++;	  
	  } 
	 infix1[i] = '\0';	  	
    cout<<infix1<<endl;
    
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
