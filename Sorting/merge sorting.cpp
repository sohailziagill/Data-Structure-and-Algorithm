#include<iostream>
#include<string.h>
#define max 50 
using namespace std;
int arr[max], arr1[max], mnky;
void divider(int, int);
void setter();
void merge(int, int, int);
void getter();
void setter()
{
    cout << "\n Enter the number of array elements \t";
    cin >> mnky;
    for (int i = 0; i < mnky; i++)
    {
        cout << "\n Enter the value in " << i + 1 << "\t";
        cin >> arr[i];
    }
    divider(0, mnky - 1);
}
void divider(int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        divider(l, mid);
        divider(mid + 1, h);
        merge(l, mid, h);
    }
}


void merge(int lb, int midb, int ub)
{
    int l, u, r, k = lb;
    l = lb;
    u = ub;
    r = midb + 1;
    //To copy small element first in other array
    while (l <= midb && r <= ub)
    {
        if (arr[l] <= arr[r])
            arr1[k++] = arr[l++];
        else
            arr1[k++] = arr[r++];
    }
    //Copy the remaining elements of left side 
    for (l; l <= midb; l++)
        arr1[k++] = arr[l];
    //Copy the remaining elements of right side 
    for (r; r <= ub; r++)
        arr1[k++] = arr[r];
    //Copy elements of 2nd array to 1st array
    for (int i = lb; i <= ub; i++)
        arr[i] = arr1[i];
}
void getter()
{
    cout << "\n The elements are \t";
    for (int i = 0; i < mnky; i++)
    {
        cout << "\n" << arr[i];
    }
}

int main()
{
    cout << "\n  /*********************************************";
    cout << "\n  Name :  Sohail Zia Gill";
    cout << "\n  Title:   Merge Sort";
    cout << "\n  Compiler : Visual Studio 19";
    cout << "\n  Dated : 25/04/2020";
    cout << "\n  Compiling date :25/04/2020";
    cout << "\n  International Islamic University Islamabad";
    cout << "\n  **********************************************/";
    setter();
    getter();
    cout << endl;
    system("pause");
    return 0;
}
