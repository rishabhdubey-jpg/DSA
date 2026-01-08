#include <iostream>
using namespace std;

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        cout << "queue Overflow.." << endl;
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "No element to dequeue.." << endl;
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = new int[q.size];

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);

    cout << "Dequeuing element " << dequeue(&q) << endl;
    cout << "Dequeuing element " << dequeue(&q) << endl;

    if (isEmpty(&q))
    {
        cout << "Queue is empty" << endl;
    }
    if (isFull(&q))
    {
        cout << "Queue is full" << endl;
    }

    return 0;
}