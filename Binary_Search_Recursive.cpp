#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void getdata(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements at index " << i << " : ";
        cin >> arr[i];
    }
}

void displaydata(int *arr, int n)
{
    cout << "Elemnts of the array are : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}

int binarySearch(int *arr, int left, int right, int key)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (key < arr[mid])
            return binarySearch(arr, left, mid - 1, key);
        else if (key > arr[mid])
            return binarySearch(arr, mid + 1, right, key);
        else
            return mid;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int key, n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int *arr = new int[n];
    getdata(arr, n);
    displaydata(arr, n);

    cout << "Enter the key you want to search : ";
    cin >> key;

    int location = binarySearch(arr, 0, n - 1, key);

    cout << "Location of " << key << "in array is " << location;

    return 0;
}