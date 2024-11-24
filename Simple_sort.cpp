#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
    
struct Array
{
    int *A;
    int size;
    int length;
};

void getData(struct Array *arr)
{
    cout<<"Enter the size of the array you want to enter : ";
    cin>>arr->size;
    arr->A = new int[arr->size];
    cout<<"Enter the number of elements youu want to enter : ";
    cin>>arr->length;
    cout<<"Enter Elements in the array : "<<endl;
    for(int i = 0 ; i<arr->length ; i++)
    {
        cout<<"Enter element at index "<<i+1<<" : ";
        cin>>arr->A[i];
    }
}

void displayData(struct Array arr)
{
    cout<<"Elements in the array : ";
    for(int i = 0 ; i<arr.length ; i++)
    {
        cout<<arr.A[i]<<"   ";
    }
    cout<<endl;
}

void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void simpleSort(struct Array *arr)
{
    for(int i = 0 ; i < arr ->length ; i++)
    {
        for(int j = i+1 ; j < arr ->length ; j++)
        {
            if(arr ->A[i] > arr ->A[j])
            {
                swap(&arr -> A[i] , &arr -> A[j]);
            }
        }
    }
}

void deleteData(struct Array *arr)
{
    cout<<"POP-UP : All array content is going to be deleted";
    delete [] arr->A;
}

int main()
{
    Array arr;
    getData(&arr);
    displayData(arr);

    simpleSort(&arr);
    cout<<"After sorting : "<<endl;
    displayData(arr);

    deleteData(&arr);
    return 0;
}