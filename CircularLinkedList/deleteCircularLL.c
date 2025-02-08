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
void deleteFront(Node **tail)
{
    if (*tail == NULL)
    {
        printf("Nothing to delete");
        return;
    }
    Node *temp = (*tail)->next;
    (*tail)->next = temp->next;
    free(temp);
}
void deleteEnd(Node **tail)
{
    if (*tail == NULL)
    {
        printf("Nothing to delete");
        return;
    }
    Node *temp = (*tail)->next;
    while (temp->next != *tail)
    {
        temp = temp->next;
    }
    temp->next = (*tail)->next;
    free(*tail);
    *tail = temp;
}
void deleteMid(Node **tail, int pos)
{
    if (*tail == NULL)
    {
        printf("Nothing to delete");
        return;
    }
    Node *t = (*tail)->next;
    while (pos - 2 > 0)
    {
        t = t->next;
        pos--;
    }
    if (t->next == *tail)
    {
        deleteEnd(tail);
        return;
    }
    Node *temp = t->next;
    t->next = temp->next;
    free(temp);
}
int main()
{
    Node *tail = NULL;
    addNodeFront(&tail, 10);
    addNodeFront(&tail, 20);
    addNodeFront(&tail, 30);
    addNodeFront(&tail, 40);
    addNodeFront(&tail, 50);
    addNodeFront(&tail, 60);
    printData(tail);
    deleteFront(&tail);
    printData(tail);
    deleteFront(&tail);
    printData(tail);
    addNodeFront(&tail, 50);
    addNodeFront(&tail, 60);
    printData(tail);
    deleteEnd(&tail);
    printData(tail);
    deleteEnd(&tail);
    printData(tail);
    deleteEnd(&tail);
    printData(tail);
    deleteMid(&tail, 2);
    printData(tail);
    deleteMid(&tail, 1);
    printData(tail);
    return 0;
}