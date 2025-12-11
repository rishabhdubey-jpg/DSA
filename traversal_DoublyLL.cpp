#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

void linkedListReverseTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->prev;
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
    head->prev = NULL;

    // Link second and third nodes
    second->data = 27;
    second->next = third;
    second->prev = head;

    // Link third and fourth nodes
    third->data = 49;
    third->next = fourth;
    third->prev = second;

    // Terminate the list at the fourth node
    fourth->data = 66;
    fourth->next = NULL;
    fourth->prev = third;

    cout << "Doubly LinkedList:" << endl;
    linkedListTraversal(head);
    cout << endl;
    cout << "Doubly LinkedList in Reverse:" << endl;
    linkedListReverseTraversal(fourth);
    return 0;
}