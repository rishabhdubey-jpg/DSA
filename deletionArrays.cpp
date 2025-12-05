#include <iostream>
using namespace std;

void display(int arr[], int n)
{ // code for Traversal
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int indDeletion(int arr[], int size, int index)
{
    // code for Deletion
    if (index < 0 || index >= size)
    {
        cout << "Invalid index, cannot delete element." << endl;
        return -1;
    }

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    cout << "Deleted element at index " << index << endl;
    return 1;
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, index = 6;
    display(arr, size);
    if (indDeletion(arr, size, index) == 1)
    {
        size--;
    }
    display(arr, size);

    return 0;
}