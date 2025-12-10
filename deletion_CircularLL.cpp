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

// Case 1: Deletion of the first node in Circular Linked List
struct Node *deleteFirstNode(struct Node *head)
{
    if (head == nullptr)
        return nullptr;

    struct Node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }

    struct Node *toDelete = head;
    if (head->next == head) // Only one node present
    {
        head = nullptr;
    }
    else
    {
        last->next = head->next;
        head = head->next;
    }
    delete toDelete;
    return head;
}

// Case 2: Deletion of a node at a given index in Circular Linked List
struct Node *deleteAtIndex(struct Node *head, int index)
{
    if (head == nullptr)
        return nullptr;

    struct Node *current = head;
    struct Node *previous = nullptr;

    // If deleting the head node
    if (index == 0)
    {
        struct Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }

        struct Node *toDelete = head;
        if (head->next == head) // Only one node present
        {
            head = nullptr;
        }
        else
        {
            last->next = head->next;
            head = head->next;
        }
        delete toDelete;
        return head;
    }

    int i = 0;
    while (i < index && current->next != head)
    {
        previous = current;
        current = current->next;
        i++;
    }

    if (i == index)
    {
        previous->next = current->next;
        delete current;
    }
    return head;
}

// Case 3: Deletion of the last node in Circular Linked List
struct Node *deleteLastNode(struct Node *head)
{
    if (head == nullptr)
        return nullptr;

    struct Node *current = head;
    struct Node *previous = nullptr;

    // If there's only one node
    if (head->next == head)
    {
        delete head;
        return nullptr;
    }

    while (current->next != head)
    {
        previous = current;
        current = current->next;
    }

    previous->next = head;
    delete current;
    return head;
}

// Case 4: Deletion of a node with a given value in Circular Linked List
struct Node *deleteNodeWithValue(struct Node *head, int value)
{
    if (head == nullptr)
        return nullptr;

    struct Node *current = head;
    struct Node *previous = nullptr;

    // If the node to be deleted is the head node
    if (head->data == value)
    {
        struct Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }

        struct Node *toDelete = head;
        if (head->next == head) // Only one node present
        {
            head = nullptr;
        }
        else
        {
            last->next = head->next;
            head = head->next;
        }
        delete toDelete;
        return head;
    }

    do
    {
        previous = current;
        current = current->next;
        if (current->data == value)
        {
            previous->next = current->next;
            delete current;
            return head;
        }
    } while (current != head);

    return head; // Value not found
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
    // head = deleteFirstNode(head); // Deleting the first node
    // head = deleteAtIndex(head, 2); // Deleting node at index 2
    // head = deleteLastNode(head); // Deleting the last node
    head = deleteNodeWithValue(head, 27); // Deleting node with value 27
    cout << endl;
    cout << "Circular LinkedList after deletion:" << endl;
    linkedListTraversal(head);

    return 0;
}