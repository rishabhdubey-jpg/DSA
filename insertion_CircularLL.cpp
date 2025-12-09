#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;

    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

// Case 1: Insertion at the beginning of Circular Linked List
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)new (struct Node);
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

// Case 2: Insertion at a given index in Circular Linked List
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

// Case 3: Insertion at the end of Circular Linked List
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)new (struct Node);
    ptr->data = data;
    struct Node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

// Case 4: Insertion after a given node in Circular Linked List
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
    fourth->next = head;

    cout << "Circular LinkedList before insertion:" << endl;
    linkedListTraversal(head);
    // head = insertAtFirst(head, 55); // Inserting 55 at the beginning
    // head = insertAtIndex(head, 55, 2); // Inserting 55 at index 2
    // head = insertAtEnd(head, 55); // Inserting 55 at the end
    head = insertAfterNode(head, third, 55); // Inserting 55 after third node
    cout << endl;
    cout << "Circular LinkedList after insertion:" << endl;
    linkedListTraversal(head);
    return 0;
}