#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node * ptr){
    while(ptr!=NULL)
    {
    printf("Element: %d\n", ptr->data);
    ptr= ptr->next;
    }
}
int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;

    //Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    //Link first and second nodes
    head->data = 7;
    head->next = second;

    //Link second and third nodes
    second->data = 11;
    second->next = third;

    //Link the list at the third node
    third->data = 66;
    third->next = NULL;

    linkedListTraversal(head);

return 0;
}
