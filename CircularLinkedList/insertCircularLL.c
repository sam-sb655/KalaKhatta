#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *createNode(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = ptr;
    return ptr;
}
void addNodeFront(Node **tail, int data)
{
    if (*tail == NULL)
    {
        *tail = createNode(data);
        return;
    }
    Node *t = createNode(data);
    t->next = (*tail)->next;
    (*tail)->next = t;
}
void addNodeEnd(Node **tail, int data)
{
    if (*tail == NULL)
    {
        *tail = createNode(data);
        return;
    }
    Node *t = createNode(data);
    t->next = (*tail)->next;
    (*tail)->next = t;
    *tail = t;
}
void addNodeMid(Node **tail, int data, int pos)
{
    Node *t = (*tail)->next;
    while (pos > 1)
    {
        t = t->next;
        pos--;
    }
    if (t == *tail)
    {
        addNodeEnd(tail, data);
        return;
    }
    Node *temp = createNode(data);
    temp->next = t->next;
    t->next = temp;
}
void printData(Node *tail)
{
    Node *temp = tail->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}
int main()
{
    Node *tail = NULL;
    addNodeFront(&tail, 10);
    addNodeFront(&tail, 20);
    addNodeFront(&tail, 30);
    addNodeFront(&tail, 40);
    addNodeFront(&tail, 50);
    printData(tail);
    addNodeEnd(&tail, 60);
    printData(tail);
    addNodeEnd(&tail, 70);
    printData(tail);
    addNodeMid(&tail, 9, 3);
    printData(tail);
    addNodeMid(&tail, 25, 2);
    printData(tail);
    addNodeMid(&tail, 49, 5);
    printData(tail);
    return 0;
}