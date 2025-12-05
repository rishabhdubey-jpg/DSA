#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low = 0, mid, high = size - 1;
    // Keep searching until low <= high
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // Unsorted array for Linear Search:
    int arr[] = {1, 3, 2, 99, 63, 55, 23, 1011, 6};
    int size = sizeof(arr)/sizeof(int);
    int element = 23;
    int searchIndex = linearSearch(arr, size, element);
    if (searchIndex != -1){
        cout<<"Element found at index: "<<searchIndex<<endl;
    } else {
        cout<<"Element not found in the array."<<endl;
    }

    // Sorted array for Binary Search:
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(int);
    int element = 14;
    int searchIndex = binarySearch(arr, size, element);
    if (searchIndex != -1)
    {
        cout << "Element " << element << " found at index: " << searchIndex << endl;
    }
    else
    {
        cout << "Element not found in the array.." << endl;
    }

    return 0;
}