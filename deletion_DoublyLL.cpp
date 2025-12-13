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

// Case 1: Deletion of the first node in Doubly Linked List
struct Node *deleteFirstNode(struct Node *head)
{
    if (head == nullptr)
        return nullptr;

    struct Node *toDelete = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    delete toDelete;
    return head;
}

// Case 2: Deletion at a given index in Doubly Linked List
struct Node *deleteAtIndex(struct Node *head, int index)
{
    if (head == nullptr)
        return nullptr;

    struct Node *current = head;
    int i = 0;

    // If deleting the head node
    if (index == 0)
    {
        struct Node *toDelete = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete toDelete;
        return head;
    }

    while (current != nullptr && i < index)
    {
        current = current->next;
        i++;
    }

    if (current != nullptr)
    {
        struct Node *toDelete = current;
        if (current->prev != nullptr)
        {
            current->prev->next = current->next;
        }
        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }
        delete toDelete;
    }
    return head;
}

// Case 3: Deletion of the last node in Doubly Linked List
struct Node *deleteLastNode(struct Node *head)
{
    if (head == nullptr)
        return nullptr;

    struct Node *current = head;

    // If there's only one node
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->prev->next = nullptr;
    delete current;
    return head;
}

// Case 4: Deletion of a node with a given value in Doubly Linked List
struct Node *deleteNodeWithValue(struct Node *head, int value)
{
    if (head == nullptr)
        return nullptr;

    struct Node *current = head;

    // If the node to be deleted is the head node
    if (head->data == value)
    {
        struct Node *toDelete = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete toDelete;
        return head;
    }

    while (current != nullptr && current->data != value)
    {
        current = current->next;
    }

    if (current != nullptr)
    {
        struct Node *toDelete = current;
        if (current->prev != nullptr)
        {
            current->prev->next = current->next;
        }
        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }
        delete toDelete;
    }
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

    cout << "Doubly LinkedList before deletion:" << endl;
    linkedListTraversal(head);
    cout << endl;
    cout << "Doubly LinkedList after deletion:" << endl;
    // head = deleteFirstNode(head); // Deleting the first node
    // head = deleteAtIndex(head, 2); // Deleting node at index 2
    // head = deleteLastNode(head); // Deleting the last node
    head = deleteNodeWithValue(head, 27); // Deleting node with value 27
    linkedListTraversal(head);

    return 0;
}