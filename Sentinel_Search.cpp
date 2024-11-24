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

void getdata(struct Array *arr)
{
    cout << "Enter the size of the array : ";
    cin >> arr->size;
    arr->A = new int[arr->size];
    cout << "Enter how many elements you want to enter in the araay : ";
    cin >> arr->length;

    for (int i = 0; i < arr->length; i++)
    {
        cout << "Enter elements at insex " << i << " : ";
        cin >> arr->A[i];
    }
}

void displaydata(struct Array *arr)
{
    cout << "Elemnts of the array are : " << endl;
    for (int i = 0; i < arr->length; i++)
    {
        cout << arr->A[i] << "   ";
    }
    cout << endl;
}

int sentinelSearch(struct Array *arr, int key)
{
    int i;
    if (arr->A[arr->length - 1] == key)
        return arr->length - 1;

    int last = arr->A[arr->length - 1];
    arr->A[arr->length - 1] = key;

    for (i = 0; arr->A[i] != key; i++)
        ;

    arr->A[arr->length - 1] = last;

    if (i <= arr->length - 1)
        return i;
    else
        return -1;
}

int main()
{
    int key;
    Array arr;
    getdata(&arr);
    displaydata(&arr);

    cout << "Enter the key you want to search : ";
    cin >> key;

    int location = sentinelSearch(&arr, key);

    cout << "Location of " << key << "in array is " << location;

    return 0;
}