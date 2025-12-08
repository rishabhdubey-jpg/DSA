#include <iostream>
using namespace std;

struct Node
{
    int data;
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

// Case 1:
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)new (struct Node);
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

// Case 2:
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)new (struct Node);
    ptr->data = data;
    struct Node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3:
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)new (struct Node);
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4:
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)new (struct Node);
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
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

    cout << "LinkedList before insertion:" << endl;
    linkedListTraversal(head);
    head = insertAtFirst(head, 55);
    cout << endl;
    cout << "LinkedList after insertion:" << endl;
    linkedListTraversal(head);

    cout << "LinkedList before insertion:" << endl;
    linkedListTraversal(head);
    cout << endl;
    head = insertAtIndex(head, 55, 1);
    cout << "LinkedList after insertion:" << endl;
    linkedListTraversal(head);

    cout << "LinkedList before insertion:" << endl;
    linkedListTraversal(head);
    cout << endl;
    head = insertAtEnd(head, 55);
    cout << "LinkedList after insertion:" << endl;
    linkedListTraversal(head);

    cout << "LinkedList before insertion:" << endl;
    linkedListTraversal(head);
    cout << endl;
    head = insertAfterNode(head, second, 55);
    cout << "LinkedList after insertion:" << endl;
    linkedListTraversal(head);

    return 0;
}