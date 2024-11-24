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

int linearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length && arr->A[i] != key; i++)
        ;

    if (i < arr->length)
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

    int location = linearSearch(&arr, key);

    cout << "Location of " << key << "in array is " << location;

    return 0;
}