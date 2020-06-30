#include<iostream>
#include<string>
#include<math.h> //for pow function
#include<stack>
#define MAX 100
using namespace std;
int calc(int a , int b, char ch)
{
   switch(ch)
   {
   	 case '+':
   	 	return a+b;
   	 break;
		case '-':
   	 	return a-b;
   	 break;
		case '*':
   	 	return a*b;
   	 break;
		case '/':
   	 	return a/b;
   	 break;
		case '^':
   	 	return pow(a,b);   	
   }	
}

int main()
{
	int a,b;	
	stack<int> mystack1; //For postfix to Ans(int)
	int m ,choice;
	char token , postfix[MAX];
do{
    m=0;	
	cout<<"Enter Postfix Expression: ";
	cin>>postfix;
	
	while(postfix[m] != '\0')
	{
		token =  postfix[m];
	    if(isalpha(token))
	       {
	       	  cout<<"Error!\nCorrect Input Next time!!!"<<endl;
	       	  goto option;
		   }
		else if(isdigit(token))	//if true push on the stack	   
		   	 mystack1.push( (static_cast<int>(token)) - 48); // static_cast<int>('1') its returns 49 so - 48 from ans to get 1
		else
		   {
		      b =  mystack1.top();
		      mystack1.pop(); //remove the top
		      a =  mystack1.top();
		      mystack1.pop(); //remove the top			  			  		       
			  mystack1.push(calc( a ,  b, token));  
		   } 		
	m++;
	}	
	cout<<"After Execution Result is : "<< mystack1.top()<<endl;
	option:
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
