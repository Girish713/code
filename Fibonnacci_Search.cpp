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

int index_of_fibonacci_number_greater_then_size(int size)
{
    int x = 0, y = 1;
    int index = 2;

    if (size == 0)
        return 0;

    while (x + y < size)
    {
        int z = x + y;
        x = y;
        y = z;
        index++;
    }

    return index;
}

int fibonacci_number_at_a_index(int k)
{
    if (k == 0)
        return 0;
    else if (k == 1)
        return 1;
    else
    {
        int x = 0;
        int y = 1;
        int z;
        for (int i = 2; i <= k; i++)
        {
            z = x + y;
            x = y;
            y = z;
        }
        return z;
    }
}

int fibonacciSearch(struct Array *arr, int key)
{
    int k = index_of_fibonacci_number_greater_then_size(arr->length);

    if (k == 0)
        return -1;

    int offset = -1;

    while (k > 0){
        int i = min(offset + fibonacci_number_at_a_index(k - 2), arr->length - 1);

        if (key == arr->A[i])
            return i;
        else if (key > arr->A[i])
        {
            k = k - 1;
            offset = i ;
        }
        else if(key < arr->A[i])
        {
            k = k - 2;
        }
    }

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

    int location = fibonacciSearch(&arr, key);

    cout << "Location of " << key << "in array is " << location;

    return 0;
}