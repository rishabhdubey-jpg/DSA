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

// Case 1: Insertion at beginning of the Doubly LinkedList
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)new (struct Node);
    ptr->data = data;

    struct Node *p = head;
    p->prev = ptr;
    ptr->next = p;
    ptr->prev = NULL;
    head = ptr;
    return head;
}

// Case 2: Insertion at a given index in Doubly Linked List
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
    ptr->prev = p;
    if (p->next != NULL)
    {
        p->next->prev = ptr;
    }
    p->next = ptr;
    return head;
}

// Case 3: Insertion at the end of Doubly Linked List
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
    ptr->prev = p;
    ptr->next = NULL;
    return head;
}

// Case 4: Insertion after a given node in Doubly Linked List
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)new (struct Node);
    ptr->data = data;

    ptr->next = prevNode->next;
    ptr->prev = prevNode;
    if (prevNode->next != NULL)
    {
        prevNode->next->prev = ptr;
    }
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

    cout << "Doubly LinkedList before insertion:" << endl;
    linkedListTraversal(head);
    cout << endl;
    cout << "Doubly LinkedList after insertion:" << endl;
    // head = insertAtFirst(head, 55); // Insert 55 at first node
    // head = insertAtIndex(head, 55, 2); // Insert 55 at index 2
    // head = insertAtEnd(head, 55); // Insert 55 at the end
    head = insertAfterNode(head, second, 55); // Insert 55 after second node
    linkedListTraversal(head);

    return 0;
}