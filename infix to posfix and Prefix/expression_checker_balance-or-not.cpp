#include<iostream>
#include<string>
#include<stack>
using namespace std;

int convert(char ch) 
{ 
   switch(ch)
   {
   	 case '[':
   	   return 1;
	 break;
	 case ']':
   	   return 1;
	 break;
	 case '{':
   	   return 2;   	   
	 break;
	 case '}':
   	   return 2;   	   
	 break;
	 case '(':
   	   return 3;   	   
	 break;
	 case ')':
   	   return 3;   	   
	 break;		
   	default:
   		return 0;
   }	
}

int main()
{
  int c1,c2,c3 , choice;
  int mytop, i;
  string exp;
  char token;
  stack<int> mystack;
do{
    c1=c2=c3=i=0;
    mytop = -1;
  cout<<"Enter Expression: ";
  cin>>exp;
  
  while(exp[i] != '\0')
  {
      token = exp[i];
	  if(token == '[' || token == ']' || token == '(' ||  token == ')' || token == '{' || token == '}')
	    {
	       mystack.push(convert(token));
		   mytop++;	    	
		}
	  i++;
  }	
	
while(mytop != -1)
{
    if( mystack.top() ==  1)
	   {
		 c1++;  
         mystack.pop();
         mytop--;
	   }
    else if( mystack.top() ==  2)
	   {
		 c2++;  
         mystack.pop();
         mytop--;
	   }
	else
	  {
		 c3++;  
         mystack.pop();
         mytop--;
	   }	      
}	

  if(c1%2==0 && c2%2==0 && c3%2==0)
    cout<<"Balance expression!"<<endl;
  else
    cout<<"NOT Balance expression!"<<endl; 

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
