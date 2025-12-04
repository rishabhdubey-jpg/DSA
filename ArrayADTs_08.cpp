#include <iostream>
using namespace std;

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(myArray *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = new int[tSize];
}

void show(const myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        cout << a->ptr[i] << "\n";
    }
}

void setVal(myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> a->ptr[i];
    }
}

int main()
{
    myArray marks;
    createArray(&marks, 10, 2);

    cout << "We are running setVal now\n";
    setVal(&marks);

    cout << "We are running show now\n";
    show(&marks);

    delete[] marks.ptr;

    return 0;
}
