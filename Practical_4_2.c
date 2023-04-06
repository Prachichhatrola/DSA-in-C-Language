#include <stdio.h>
#include <stdlib.h>
struct node
{
struct node *pre;
int data;
struct node *next;
};
void display(struct node *head)
{
if(head == NULL)
{
printf("\n The linked list is empty");
}
if (head->next == NULL)
{
printf("\n The linked list is empty");
}
printf("\n The element of the linked list are as follow : ");
while (head->next != NULL)
{
printf("%d ", head->data);
head = head->next;
}
printf("%d ", head->data);
}
struct node *add_at_empty(struct node *head, int data)
{
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
temp->pre = NULL;
temp->data = data;
temp->next = NULL;
head = temp;
return head;
}
struct node *add_at_beg(struct node *head, int data)
{
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
temp->pre = NULL;
temp->data = data;
temp->next = NULL;
temp->next = head;
head->pre = temp;
head = temp;
return head;
}
void add_at_end(struct node *head, int data)
{
struct node *temp, *ptr;
temp = (struct node *)malloc(sizeof(struct node));
ptr = head;
temp->pre = NULL;
temp->data = data;
temp->next = NULL;
while (ptr->next != NULL)
{
ptr = ptr->next;
}
ptr->next = temp;
temp->pre = ptr;
}
void add_at_before(struct node *head, int data, int olddata)
{
struct node *temp, *ptr;
temp = (struct node *)malloc(sizeof(struct node));
temp->pre = NULL;
temp->data = data;
temp->next = NULL;
ptr = head;
while (ptr->data != olddata)
{
ptr = ptr->next;
}
/*temp -> next = ptr;
head -> next = temp;
head -> next -> pre = temp;
temp -> pre = head;*/
temp->next = ptr;
temp->pre = ptr->pre;
ptr->pre->next = temp;
ptr->pre = temp;
}
void add_at_after(struct node *head, int data, int olddata)
{
struct node *temp, *ptr;
temp = (struct node *)malloc(sizeof(struct node));
temp->pre = NULL;
temp->data = data;
temp->next = NULL;
ptr = head;
while (ptr->data != olddata)
{
ptr = ptr->next;
}
temp->pre = ptr;
temp->next = ptr->next;
ptr->next->pre = temp;
ptr->next = temp;
}
void delete (struct node *head, int data)
{
struct node *temp;
temp = head;
while (temp->data != data)
{
temp = temp->next;
}
temp->pre->next = temp->next;
temp->next->pre = temp->pre;
free(temp);
}
void delete_at_after(struct node *head, int data)
{
struct node *temp;
temp = head;
while (temp->data != data)
{
temp = temp->next;
}
temp->next->next->pre = temp;
temp->next = temp->next->next;
free(temp->next);
// head = temp;
}
void delete_at_before(struct node *head, int data)
{
struct node *temp;
temp = head;
while (temp->data != data)
{
temp = temp->next;
}
temp->pre->pre->next = temp;
temp->pre = temp->pre->pre;
free(temp->pre);
// head = temp;
}
struct node *delete_at_beg(struct node *head)
{
struct node *ptr, *temp;
ptr = head;
temp = ptr->next;
temp->pre = NULL;
head = temp;
free(ptr);
return head;
}
void delete_at_end(struct node *head)
{
struct node *temp;
temp = head;
while(temp -> next != NULL)
{
temp = temp -> next;
}
temp -> pre -> next = NULL;
free(temp);
}
int main()
{
printf("\nName: Prachi Chhatrola\n");
printf("enroll.no.- 210210116030\n");
struct node *head;
int data, olddata, ch;
while (1)
{
printf("\n1.Creating a node\n2.Insertion at beginning\n3.Insertion at
End\n4.Insertion before a value\n5.Insertion after the value\n6.Delete a
specific node\n7.Delete after a value\n8.Delete before a value\n9.Delete at
beginning\n10.Delete at end\n12.Quit");
printf("\nEnter the choice = ");
scanf("%d", &ch);
switch (ch)
{
case 1:
printf("\n Enter the data which you want to add = ");
scanf("%d", &data);
head = add_at_empty(head, data);
printf("%d ", head->data);
break;
case 2:
printf("\n Enter the data which you want to add at beginning =
");
scanf("%d", &data);
head = add_at_beg(head, data);
display(head);
break;
case 3:
printf("\n Enter the data which you want to add at end = ");
scanf("%d", &data);
add_at_end(head, data);
display(head);
break;
case 4:
printf("\n Enter the old data before which the data is inserted =
");
scanf("%d", &olddata);
printf("\n Enter the New data which will be added before %d = ",
olddata);
scanf("%d", &data);
add_at_before(head, data, olddata);
display(head);
break;
case 5:
printf("\n Enter the old data afte which the data is inserted =
");
scanf("%d", &olddata);
printf("\n Enter the New data which will be added before %d = ",
olddata);
scanf("%d", &data);
add_at_after(head, data, olddata);
display(head);
break;
case 6:
printf("\n Enter the data which you want to delete = ");
scanf("%d", &data);
delete (head, data);
display(head);
break;
case 7:
printf("\n Enter the data which you want to delete after = ");
scanf("%d", &data);
delete_at_after(head, data);
display(head);
break;
case 8:
printf("\n Enter the data which you want to delete before = ");
scanf("%d", &data);
delete_at_before(head, data);
display(head);
break;
case 9:
head = delete_at_beg(head);
display(head);
break;
case 10:
delete_at_end(head);
display(head);
break;
case 11:
exit(1);
}
}
return 0;
}