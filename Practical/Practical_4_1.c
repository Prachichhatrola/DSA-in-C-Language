#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *link;
};
void print(struct node *ptr)
{
if (ptr == NULL)
{
printf("\n The linked list is empty");
}
struct node *ptr2;
ptr2 = ptr;
printf("\n The element of the linked list are : ");
while (ptr2 != NULL)
{
printf("%d ", ptr2->data);
ptr2 = ptr2->link;
}
}
struct node *add_at_beg(struct node *ptr, int newdata)
{
struct node *ptr2;
ptr2 = (struct node *)malloc(sizeof(struct node));
ptr2->data = newdata;
ptr2->link = NULL;
ptr2->link = ptr;
ptr = ptr2;
}
void add_at_end(struct node *ptr, int newdata)
{
struct node *ptr2, *ptr3;
ptr2 = ptr;
ptr3 = (struct node *)malloc(sizeof(struct node));
ptr3->data = newdata;
ptr3->link = NULL;
while (ptr2->link != NULL)
{
ptr2 = ptr2->link;
}
ptr2->link = ptr3;
}
void add_at_after(struct node *head, int newdata, int olddata)
{
struct node *ptr4, *ptr5, *ptr6;
ptr4 = head;
ptr5 = (struct node *)malloc(sizeof(struct node));
ptr5->data = newdata;
ptr5->link = NULL;
while (ptr4->data != olddata)
{
ptr4 = ptr4->link;
}
ptr6 = ptr4->link;
ptr4->link = ptr5;
ptr5->link = ptr6;
}
void add_at_before(struct node *head, int newdata, int olddata)
{
struct node *ptr7, *ptr8, *temp;
ptr7 = head;
ptr8 = (struct node *)malloc(sizeof(struct node));
ptr8->data = newdata;
ptr8->link = NULL;
while (ptr7->data != olddata)
{
temp = ptr7;
ptr7 = ptr7->link;
}
ptr8->link = ptr7;
temp->link = ptr8;
}
void delete (struct node *head, int data)
{
struct node *temp, *ptr;
temp = head;
while (temp->data != data)
{
ptr = temp;
temp = temp->link;
}
ptr->link = temp->link;
free(temp);
}
void delete_at_after(struct node *head, int data)
{
struct node *temp, *ptr;
temp = head;
while (head->data != data && head->link != NULL)
{
head = head->link;
}
if (head->data == data)
{
ptr = head->link;
head->link = head->link->link;
free(ptr);
}
else
{
printf("\n data is not found ");
}
head = temp;
}
void delete_at_before(struct node *head, int data)
{
struct node *temp, *ptr = NULL, *ptr2 = NULL;
temp = head;
while (temp->data != data)
{
ptr2 = ptr;
ptr = temp;
temp = temp->link;
}
ptr2->link = temp;
free(ptr);
}
struct node *delete_at_beginnig(struct node *head)
{
struct node *temp, *ptr;
ptr = head;
temp = head->link;
free(ptr);
return temp;
}
void delete_at_end(struct node *head)
{
struct node *temp, *ptr;
temp = head;
while (temp != NULL)
{
ptr = temp;
temp = temp->link;
}
ptr->link = NULL;
free(temp);
}
struct node *delete_list(struct node *head)
{
struct node *temp;
while (temp != NULL)
{
temp = temp->link;
free(head);
head = temp;
}
return head;
}
int main()
{
printf("Prachi chhatrola\n");
printf("210210116030\n");
int data, data1, data2;
struct node *head, *temp, *beg, *end, *dbeg;
head = (struct node *)malloc(sizeof(struct node));
printf("enter First data = ");
scanf("%d", &data);
head->data = data;
head->link = NULL;
temp = (struct node *)malloc(sizeof(struct node));
printf("Enter second data = ");
scanf("%d", &data1);
temp->data = data1;
temp->link = NULL;
head->link = temp;
temp = (struct node *)malloc(sizeof(struct node));
printf("Enter third data = ");
scanf("%d", &data2);
temp->data = data2;
temp->link = NULL;
head->link->link = temp;
while (1)
{
int ch;
printf("\n1.Add at beginning\n2.Add at end\n3.Add data after a
value\n4.Add data before a value\n5.Delete a specific node\n6.Delete
After a value\n7.Delete before a value\n8.Delete a first
data\n9.Delete a last data\n10.Delete the entire linked list
\n11.Quit");
printf("\n Enter the choice = ");
scanf("%d", &ch);
int adddata1, adddata2, bdata, odata, adata, pdata;
switch (ch)
{
case 1:
printf("\n Enter the data which you want to add at beginning = ");
scanf("%d", &adddata1);
beg = add_at_beg(head, adddata1);
head = beg;
print(head);
break;
case 2:
printf("\n Enter the data which you want to add at end = ");
scanf("%d", &adddata2);
add_at_end(head, adddata2);
print(head);
break;
case 3:
printf("\n Enter the New data which you want to add = ");
scanf("%d", &adata);
printf("\n Enter the data after which new data would beadded = ");
scanf("%d", &odata);
add_at_after(head, adata, odata);
print(head);
break;
case 4:
printf("\n Enter the New data which you want to add = ");
scanf("%d", &bdata);
printf("\n Enter the data before which you want to add = ");
scanf("%d", &pdata);
add_at_before(head, bdata, pdata);
print(head);
break;
case 5:
printf("\n Enter the data which you want to delete = ");
scanf("%d", &data);
delete (head, data);
print(head);
break;
case 6:
printf("\n Enter the data which you want to delete after
the value = ");
scanf("%d", &data);
delete_at_after(head, data);
print(head);
break;
case 7:
printf("\n Enter the data which you want to delete before a value = ");
scanf("%d", &data);
delete_at_before(head, data);
print(head);
break;
case 8:
head = delete_at_beginnig(head);
print(head);
break;
case 9:
delete_at_end(head);
print(head);
break;
case 10:
head = delete_list(head);
print(head);
break;
case 12:
exit(1);
break;
}
}
return 0;
}