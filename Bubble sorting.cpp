#include<iostream>
#include<string.h>
using namespace std;
# define max 1000
int main()
{
	int mnky=0,arr[max];
	bool isswap;
	cout << "\n Enter the number of students \t";
	cin >> mnky;
	for (int i = 0; i < mnky ; i++)
	{
		cout << "\n Enter the number in " << i + 1 << " \t";
		cin >> arr[i];
	}
	for (int i = 0; i < mnky - 1; i++)
	{
		isswap = false;
		for (int j = 0; j < mnky - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				isswap = true;
			}
		}
		if (isswap == false)
				break;
	}
	cout << "\n \n\n After the sorting \t";
	for (int i = 0; i < mnky; i++)
		cout << "\n " << arr[i];
	cout << endl;
	system("pause");
	return 0;
}
