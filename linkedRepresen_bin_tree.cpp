#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = new Node; // Allocating memory in the heap
    n->data = data;            // Setting the data
    n->left = nullptr;         // Setting the left and right children to NULL
    n->right = nullptr;        // Setting the left and right children to NULL
    return n;                  // Finally returning the created node
}

int main()
{
    /*
    // Constructing the root node
    struct Node *p = new Node;
    p->data = 5;
    p->left = nullptr;
    p->right = nullptr;

    // Constructing the second node
    struct Node *p1 = new Node;
    p1->data = 3;
    p1->left = nullptr;
    p1->right = nullptr;

    // Constructing the third node
    struct Node *p2 = new Node;
    p2->data = 7;
    p2->left = nullptr;
    p2->right = nullptr;
    return 0;
    */

    // Constructing the root node - Using the function (Recommended)
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(7);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    return 0;
}