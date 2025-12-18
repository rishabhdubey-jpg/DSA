#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)new (struct Node);
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        cout << "Stack Overflow!" << endl;
        return top;
    }
    else
    {
        struct Node *n = (struct Node *)new (struct Node);
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node *tp)
{
    if (isEmpty(tp))
    {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    else
    {
        struct Node *n = tp;
        top = tp->next;
        int x = n->data;
        delete n;
        return x;
    }
}

int stackTop(struct Node *ptr)
{
    if (ptr == NULL)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    return ptr->data;
}

int stackBottom(struct Node *ptr)
{
    if (ptr == NULL)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        return ptr->data;
    }
}

int peek(int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 23);

    linkedListTraversal(top);

    // int element = pop(top);
    // cout << "Popped element is " << element << endl;
    // linkedListTraversal(top);

    cout << "The Top most value of the stack is : " << stackTop(top) << endl;
    cout << "The Bottom most value of the stack is: " << stackBottom(top) << endl;

    for (int i = 1; i <= 4; i++)
    {
        cout << "Value at position " << i << " is: " << peek(i) << endl;
    }

    return 0;
}