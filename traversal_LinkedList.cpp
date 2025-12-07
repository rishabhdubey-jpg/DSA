#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void traversalLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linkedlist in Heap
    head = (struct Node *)new (struct Node);
    second = (struct Node *)new (struct Node);
    third = (struct Node *)new (struct Node);
    fourth = (struct Node *)new (struct Node);

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 27;
    second->next = third;

    // Link third and fourth nodes
    third->data = 49;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 66;
    fourth->next = NULL;

    traversalLinkedList(head);
    return 0;
}