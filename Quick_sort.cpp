#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct Array
{
    int *A;
    int length;
};

void getdata(struct Array *arr)
{
    cout << "Enter the length of the array : ";
    cin >> arr->length;

    arr->A = new int[arr->length];

    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < arr->length; i++)
    {
        cout << "Enter element at index " << i + 1 << " : ";
        cin >> arr->A[i];
    }
}

void displaydata(struct Array *arr)
{
    cout << "Elements of the array are : ";
    for (int i = 0; i < arr->length; i++)
    {
        cout << arr->A[i] << "     ";
    }
}

void swap(int *a , int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *A , int l , int r)
{
    int pivote = A[r];
    int i = l-1;

    for(int j = l ; j < r ; j++)
    {
        if(A[j]<pivote)
        {
            i++;
            swap(&A[i] , &A[j]);
        }
    }

    swap(&A[i+1] , &A[r]);
    return i+1;
}

void Quick_sort(int *A , int l , int r)
{
    if(l<r)
    {
        int index = partition(A,l,r);

        Quick_sort(A,l,index-1);
        Quick_sort(A,index+1,r);
    }
}

int main()
{
    Array arr;
    getdata(&arr);
    cout<<"Original Array: "<<endl;
    displaydata(&arr);
    cout<<"Sored Array : ";
    Quick_sort(arr.A , 0 , arr.length);
    displaydata(&arr);

    return 0;
}