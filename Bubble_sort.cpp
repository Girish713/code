// This program of Bubble Sort showing each and every pass while sorting ine data.
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

void swap(int *a , int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble_sort(struct Array *arr)
{
    for (int i = 0; i < arr->length-1; i++)
    {
        for (int  j = 0; j < arr->length; j++)
        {
            if(arr->A[j] > arr->A[j+1])
            {
                swap(&arr->A[j] , &arr->A[j+1]);
            }
        }
        
    }
    
}

// void Bubble_sort(struct Array *arr)
// {
//     for (int i = 0; i < arr->length - 1; i++)
//     {
//         for (int j = 0; j < arr->length - i; j++)
//         {
//             if(arr->A[j] > arr->A[j+1])
//             {
//                 swap(arr->A[j] , arr->A[j+1]);
//             }
//         }
        
//     }
// }

void deleteData(struct Array *arr)
{
    cout<<"POP-UP : All array content is going to be deleted";
    delete [] arr->A;
}

int main()
{
    struct Array arr;
    getData(&arr);
    displayData(arr);    

    Bubble_sort(&arr);

    cout<<"Sorted array : "<<endl;
    displayData(arr);

    // deleteData(&arr);

    return 0;
}