// This code is for merge sort
// There are some errors solve that

#include <iostream>
using namespace std;

void getdata(int *arr, int size)
{
    cout << "Enter elements of the array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter elements at index " << i << " : ";
        cin >> arr[i];
    }
}

void displaydata(int *arr, int size)
{
    cout << "Elements in the array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}
    
// void copy_element(int *source, int start, int *destination, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         destination[i] = source[start + i];
//     }
// }

void merge(int *arr, int left, int mid, int right)
{
    int s1 = mid + 1 - left;
    int s2 = right - mid;

    int *lh = new int[s1];
    int *rh = new int[s2];

    // copy_element(arr, left, lh, s1);
    // copy_element(arr, mid + 1, rh, s2);

    for (int i = 0; i < s1; i++)
    {
        lh[i] = arr[left + i];
    }
    for (int i = 0; i < s2; i++)
    {
        rh[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < s1 && j < s2)
    {
        if (lh[i] < rh[j])
        {
            arr[k] = lh[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rh[j];
            j++;
            k++;
        }
    }
    while (i < s1)
    {
        arr[k] = lh[i];
        i++;
        k++;
    }
    while (j < s2)
    {
        arr[k] = rh[j];
        j++;
        k++;
    }

    delete[] lh;
    delete[] rh;
}

void merge_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int size;
    cout << "Enter the sizeof the array : ";
    cin >> size;
    int *arr = new int[size];
    getdata(arr, size);
    cout << "Original array : ";
    displaydata(arr, size);

    merge_sort(arr, 0, size - 1);

    cout << "Sorted array : ";
    displaydata(arr, size);

    return 0;
}