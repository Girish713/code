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

// void Incertion_sort(struct Array *arr)
// {
//     for(int i = 1 ; i < arr->length ; i++)
//     {
//         int curr_ele = arr->A[i];
//         int j = i-1;
//         while(arr->A[j] > curr_ele && j >= 0)
//         {
//             arr->A[j+1] = arr->A[j];
//             j--;
//         }
//         arr->A[j+1] = curr_ele;
//     }
// }

void Incertion_sort(struct Array *arr)
{
    for(int i = 1 ; i < arr->length ; i++)
    {
        int curr_ele = arr->A[i];
        int j = i-1;
        while(arr->A[j] > curr_ele && j >= 0)
        {
            swap(&arr->A[j] , &arr->A[j+1]);
            j--;
        }
        arr->A[j+1] = curr_ele;
    }
}

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

    Incertion_sort(&arr);

    cout<<"Sorted array : "<<endl;
    displayData(arr);

    // deleteData(&arr);

    return 0;
}