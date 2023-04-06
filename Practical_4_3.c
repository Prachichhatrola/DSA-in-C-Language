#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
int data;
struct node *link;
};
void print(struct node *head)
{
struct node *temp;
temp = head;
while (temp->link != head)
{
printf("%d ", temp->data);
temp = temp->link;
}
printf("%d", temp->data);
}
struct node *add_at_beg(struct node *head, int data)
{
struct node *temp,
*ptr;
ptr = head;
temp = (struct node *)malloc(sizeof(struct node));
temp->data = data;
while (ptr->link != head)
{
ptr = ptr->link;
}
temp->link = head;
ptr->link = temp;
head = temp;
return head;
}
void add_at_end(struct node *head, int data)
{
struct node *temp,
*ptr;
temp = head;
ptr = (struct node *)malloc(sizeof(struct node));
ptr->data = data;
ptr->link = NULL;
while (temp->link != head)
{
temp = temp->link;
}
temp->link = ptr;
ptr->link = head;
}
void add_at_after(struct node *head, int olddata, int data)
{
struct node *temp,
*ptr;
temp = head;
ptr = (struct node *)malloc(sizeof(struct node));
ptr->data = data;
ptr->link = NULL;
while (temp->data != olddata)
{
temp = temp->link;
}
ptr->link = temp->link;
temp->link = ptr;
}
void add_at_before(struct node *head, int olddata, int data)
{
struct node *temp,
*ptr,
*pre;
ptr = (struct node *)malloc(sizeof(struct node));
ptr->data = data;
ptr->link = NULL;
temp = head;
while (temp->data != olddata)
{
pre = temp;
temp = temp->link;
}
ptr->link = temp;
pre->link = ptr;
}
int delete(struct node *head, int data)
{
struct node *temp,
*pre;
temp = head;
while (temp->data != data)
{
pre = temp;
temp = temp->link;
}
pre->link = temp->link;
return temp->data;
free(temp);
}
int delete_at_after(struct node *head, int data)
{
struct node *temp,
*ptr;
temp = head;
while (temp->data != data)
{
temp = temp->link;
}
ptr = temp->link;
temp->link = ptr->link;
return ptr->data;
free(ptr);
}
int delete_at_before(struct node *head, int data)
{
struct node *temp,
*ptr = NULL,
*pre = NULL;
temp = head;
while (temp->data != data)
{
pre = ptr;
ptr = temp;
temp = temp->link;
}
pre->link = temp;
return ptr->data;
free(ptr);
}
struct node *delete_at_beginning(struct node *head, int
data)
{
struct node *temp,
*ptr = NULL;
temp = head;
while (temp->link != head)
{
temp = temp->link;
}
temp->link = head->link;
return head->link;
printf("\n The delete element is = %d", temp->data);
free(head);
}
int delete_at_end(struct node *head, int value)
{
struct node *temp,
*pre;
temp = head;
while (temp->link != head)
{
pre = temp;
temp = temp->link;
}
pre->link = head;
return temp->data;
free(temp);
}
int main()
{
printf("\nName: Prachi Chhatrola\n");
printf("enroll.no.: 210210116030");
printf("\n ****CIRCULAR LINKED LIST****");
struct node *head;
int data, olddata, ddata;
head = (struct node *)malloc(sizeof(struct node));
printf("\n Enter the first data = ");
scanf("%d", &data);
head->data = data;
head->link = NULL;
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
printf("\n Enter the second data = ");
scanf("%d", &data);
temp->data = data;
temp->link = head;
head->link = temp;
temp = (struct node *)malloc(sizeof(struct node));
printf("\n Enter the third data = ");
scanf("%d", &data);
temp->data = data;
temp->link = head;
head->link->link = temp;
int ch, value;
while (1)
{
printf("\n CIRCULAR LINKEDLIST");
printf("\n1.Insert at Begnning \n 2.Insert at End \n
3.Insert at after \n 4.Insert at before \n 5.Delete a
specific data \n 6.Delete at after \n 7.Delete at before \n
8.Delete at Beginning \n 9.Delete at End \n 12.Exit");
printf("\n Enter the choice = ");
scanf("%d", &ch);
switch (ch)
{
case 1:
printf("\n Enter the new Value = ");
scanf("%d", &value);
head = add_at_beg(head, value);
print(head);
break;
case 2:
printf("\n Enter the new value = ");
scanf("%d", &value);
add_at_end(head, value);
print(head);
break;
case 3:
printf("\n Enter the new value = ");
scanf("%d", &value);
printf("\n Enter the old data after which you want to add
after = ");
scanf("%d", &olddata);
add_at_after(head, olddata, value);
print(head);
break;
case 4:
printf("\n Enter the new value = ");
scanf("%d", &value);
printf("\n Enter the old data after which you want to add
before = ");
scanf("%d", &olddata);
add_at_before(head, olddata, value);
print(head);
break;
case 5:
printf("\nEnter the value which you want to delete = ");
scanf("%d", &value);
ddata = delete (head, value);
printf("\n The Deleted element is = %d\n", ddata);
print(head);
break;
case 6:
printf("\nEnter the value which you want to delete after =
");
scanf("%d", &value);
ddata = delete_at_after(head, value);
printf("\n The Deleted element is = %d\n", ddata);
print(head);
break;
case 7:
printf("\nEnter the value which you want to delete before =
");
scanf("%d", &value);
ddata = delete_at_before(head, value);
printf("\n The Deleted element is = %d\n", ddata);
print(head);
break;
case 8:
head = delete_at_beginning(head, value);
print(head);
break;
case 9:
ddata = delete_at_end(head, value);
printf("\n The deleted element is = %d\n", ddata);
print(head);
break;
case 11:
printf("\n The remaining element in the Linked list are :
\n");
printf(head);
break;
case 12:
exit(1);
break;
default:
printf("\n Enter the proper choice");
break;
}
}
return 0;
}