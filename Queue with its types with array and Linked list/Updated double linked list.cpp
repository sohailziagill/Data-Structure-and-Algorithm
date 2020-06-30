#include<iostream>
using namespace std;
struct node
{
	int marks;
	node* right;
	node* left;
};
void menu(int& x)
{
	cout << "\n Enter 1 for creating list         \t";
	cout << "\n Enter 2 for insertioin in list    \t";
	cout << "\n Enter 3 for searching in list     \t";
	cout << "\n Enter 4 for deletion in list       \t";
	cout << "\n Enter 5 for display the full list \t";
	cout << "\n Enter 6 for exit from the list    \t";
	cin >> x;

}
int main()
{
	int choice;
	int x;
	node* head = NULL;
	node* last = NULL;
	node* curr = NULL;
	node* prev = NULL;
	do
	{
		menu(x);
		switch (x)
		{
		case 1:
		{
			//To create the doubly link list
			do
			{
				curr = new node;
				curr->right = NULL;
				curr->left = NULL;
				do
				{
				
				cout << "\n Enter the marks ";
				cin >> curr->marks;
				if(curr->marks<0)
				cout<<"\n A negative number is not allowed ";
			    }while(curr->marks<0);
				if (head == NULL)
				{
					head = prev= last = curr;
				}
				else
				{
					curr->left = prev;
					prev->right = curr;
					prev = curr;
					last=curr;
				}

				do
				{
					cout << "\n To enter data press 1 and press 0 for stop entering data\t ";
					cin >> choice;
					if (choice < 0 || choice>1)
						cout << "\n Invalid input ";
				} while (choice < 0 || choice >1);

			} while (choice == 1);
			break;
		}
		case 2:
		{
						// To insert new linked list
			if(head==NULL)
				cout<<"\n The list is empty.\tPlease create a list\n ";
			else
			{
		    	curr = prev = head;
		    	bool isinsert = false;
		    	node* newitem;
		    	newitem = new node;
		    	newitem->left = NULL;
			    newitem->right = NULL;
			    do
			    {
		    	cout << "\n Enter the marks \t";
		    	cin >> newitem->marks;
		    	if(newitem->marks<0)
		    	cout<<"\n A negative number is not allowed ";
		        }while(newitem->marks<0);
			//insertion at beginning
			    if (newitem->marks <= head->marks)
		        {
				    head->left = newitem;
				    newitem->right = head;
				    head = newitem;
			    	isinsert = true;
			    }
			// Insertion at middle 
			while (curr != NULL)
			{
				if (newitem->marks >= curr->marks)
				{
					prev = curr;
					curr = curr->right;
				}
				else
				{
					prev->right = newitem;
					newitem->left = prev;
					curr->left = newitem;
					newitem->right = curr;
					isinsert = true;
					break;
				}
			}
			// inssertiion at end
			if (!isinsert)
			{
				prev->right = newitem;
				newitem->left = prev;
				last=newitem;
			}
			// To display linked list Again
			curr = head;
			while (curr != NULL)
			{
				cout << "\n The marks are  " << curr->marks;
				curr = curr->right;
			}
		}
			break;
		}
		case 3:
		{
			// To search in doubly linked list
			if(head==NULL)
			cout<<"\n The list is empty\t Please create a list first \n";
			else
			{
			
			int smark;
			bool isfound = false;
			do
			{
			cout << "\n Enter the marks that you want to search\t";
			cin >> smark;
			if(smark<0)
			cout<<"\n A negative number is not allowed ";
		    }while(smark<0);
			curr = head;
			if((head->right==NULL) && (head->marks==smark))
			cout<<"\n The givven number is found at 1st position \n";
			else
			{
			while (curr != NULL)
			{
				if (curr->marks == smark)
				{
					isfound = true;
					break;
				}
				else
					curr = curr->right;
			}
		}
			if (isfound)
				cout << "\n The givven mark is found in this list ";
			else
				cout << "\n The givven mark is not exist in this list ";
		}
			break;
		}
		case 4:
		{
			//           Deletion in linked list
			if(head==NULL)
			cout<<"\n The lsit is empty \t Please create a list first\n ";
			else
			{
			curr = prev = head;
			bool isdelete = false;
			int dmark;
			do
			{
			cout << "\n Enter the number that you want to delete  ";
			cin >> dmark;
			if(dmark<0)
			cout<<"\n A negative number is not allowed ";
		    }while(dmark<0);
			// deletion at start
			if(head->right==NULL)
			{
				curr=head;
				head=NULL;
				delete curr;
			}
			else
			{
			if (dmark == head->marks)
			{
				head = head->right;
				head->left = NULL;
				delete curr;
				isdelete = true;
			}
		  
			// deletion at  middle 
			else
			{
				while (curr != NULL)
				{
					if (dmark == curr->marks)
					{
						if(curr->right!=NULL)
						{
						
						cout<<"\n The numer is found ";
						prev->right = curr->right;
						prev = curr;
						curr = curr->right;
						curr->left = prev->left;
						delete prev;
                        isdelete =true;
                        }
                        // Deletion at end
                        else
                        {
                        	prev->right=NULL;
					        delete curr;
					        isdelete=true;
						}
                        
						break;
					}
					else
					{
						prev = curr;
						curr = curr->right;
					}
				}
			}
			
                    if(!isdelete)
                    {
                    cout<<"\n not deleted";	
					}
                    else
                    cout<<"\n Deleted ";
                }
        }
			break;
		}
		case 5:
		{
						// To display linked list
			if(head==NULL)
			cout<<"\n The list is empty\t Please create the list first\n ";
			else
			{
			curr = head;
			while (curr != NULL)
			{
				cout << "\n The marks are  " << curr->marks;
				curr = curr->right;
			}
		}
			break;
		}
		case 6:
		{
			exit(-1);
		}
		default:
			break;
		}
	}while (1);
	cout << endl;
	system("pause");
	return 0;
}
