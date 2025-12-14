#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

// Check if stack is empty
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Check if stack is full
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = new int[s.size];

    struct stack *s = (struct stack *)new (struct stack);
    s->size = 6;
    s->top = -1;
    s->arr = new int[s->size];

    if (isEmpty(s)) // Check if stack is empty
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    s->arr[0] = 7; // Manually, pushing elements to stack
    s->top++;

    if (isEmpty(s)) // Check if stack is empty
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    s->arr[1] = 27;
    s->top++;
    s->arr[2] = 49;
    s->top++;
    s->arr[3] = 66;
    s->top++;
    s->arr[4] = 89;
    s->top++;

    if (isFull(s)) // Check if stack is full
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Stack is not full" << endl;
    }

    s->arr[5] = 99;
    s->top++;

    if (isFull(s)) // Check if stack is full
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Stack is not full" << endl;
    }

    return 0;
}