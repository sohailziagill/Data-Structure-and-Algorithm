#include<iostream>
#include<string.h>
#define max 50 
using namespace std;
int arr[max], mnky;
int partition(int, int);
void setter();
void sort(int, int);
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
    sort(0, mnky - 1);
}
void sort(int lb, int ub)
{
    int p_loc;
    if (lb < ub)
    {
        p_loc = partition(lb, ub);
        sort(lb, p_loc - 1);
        sort(p_loc + 1, ub);
    }
}
int partition(int lb, int ub)
{
    int start, end, pivot;
    start = lb;
    end = ub;
    pivot = arr[lb];
    while (start < end)
    {
        while ((arr[start] <= pivot) || arr[end] > pivot)
        {
            if (arr[start] <= pivot)
                start++;
            if (arr[end] > pivot)
                end--;
        }
        if (start < end)
            swap(arr[start], arr[end]);

    }
    swap(arr[lb], arr[end]);
    return end;
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

