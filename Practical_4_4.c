#include <stdio.h>
#include <stdlib.h>
struct node
{
struct node *pre;
int data;
struct node *link;
};
void print(struct node *head)
{
struct node *temp;
temp = head;
while(temp -> link != head)
{
printf("%d ",temp -> data);
temp = temp -> link;
}
printf("%d",temp -> data);
}
struct node * add_at_beg(struct node * head,int data)
{
struct node *temp,*ptr;
temp = head;
ptr = (struct node *)malloc(sizeof(struct node));
ptr -> data = data;
ptr -> link = NULL;
ptr -> pre = NULL;
while(temp -> link != head)
{
temp = temp -> link;
}
temp -> link = ptr;
ptr -> pre = temp;
ptr -> link = head;
head -> pre = ptr;
return ptr;
}
void add_at_end(struct node *head,int data)
{
struct node *temp,*ptr;
temp = head;
ptr = (struct node *)malloc(sizeof(struct node));
ptr -> data = data;
ptr -> pre = NULL;
ptr -> link = NULL;
while(temp -> link != head)
{
temp= temp -> link;
}
temp -> link = ptr;
ptr -> pre = temp;
ptr -> link = head;
head -> pre = ptr;
}
void add_at_after(struct node *head,int data,int value)
{
struct node *temp,*ptr;
temp = head;
ptr = (struct node *)malloc(sizeof(struct node));
ptr -> data = value;
ptr -> link = NULL;
ptr -> pre = NULL;
while(temp -> data != data)
{
temp = temp -> link;
}
temp -> link -> pre = ptr;
ptr -> link = temp -> link;
temp -> link = ptr;
ptr -> pre = temp;
}
void add_at_before(struct node *head,int data,int value)
{
struct node *temp,*ptr;
temp = head;
ptr = (struct node *)malloc(sizeof(struct node));
ptr -> data = value;
ptr -> link = NULL;
ptr -> pre = NULL;
while(temp -> data != data)
{
temp = temp -> link;
}
temp -> pre -> link = ptr;
ptr -> pre = temp -> pre;
temp -> pre = ptr;
ptr -> link = temp;
}
int delete_a_node(struct node *head,int data)
{
struct node *temp,*ptr;
temp = head;
// ptr = NULL;
while(temp -> data != data)
{
// ptr = temp;
temp = temp -> link;
}
temp -> pre -> link = temp -> link;
temp -> link -> pre = temp -> pre;
return temp -> data;
free(temp);
}
int del_at_after(struct node *head,int data)
{
struct node *temp,*ptr;
temp = head;
ptr = NULL;
while(temp -> data != data)
{
temp = temp -> link;
}
ptr = temp -> link;
temp -> link = ptr -> link;
ptr -> link -> pre = temp;
return ptr -> data;
free(ptr);
}
int del_at_before(struct node *head,int data)
{
struct node *temp,*ptr;
temp = head;
ptr = NULL;
while(temp -> data != data)
{
ptr =temp;
temp = temp -> link;
}
temp -> pre = ptr -> pre;
ptr -> pre -> link = temp;
return ptr -> data;
free(ptr);
}
struct node *del_at_beg(struct node *head)
{
struct node *temp;
temp = head;
while(temp -> link != head)
{
temp = temp -> link;
}
temp -> link = head -> link;
head -> link -> pre = temp;
return head -> link;
free(head);
}
int del_at_end(struct node *head)
{
struct node *temp;
temp = head;
while(temp -> link != head)
{
temp = temp -> link;
}
temp -> pre -> link = temp -> link;
temp -> link -> pre = temp -> pre;
return (temp -> data);
free(temp);
}
int main()
{
printf("\nName: Prachi Chhatrola\n");
printf("enroll.no.: 210210116030");
int data;
struct node *head,*temp;
head = (struct node *)malloc(sizeof(struct node));
printf("\n Enter the first element = ");
scanf("%d",&data);
head -> pre = NULL;
head -> data = data;
head -> link = NULL;
temp = (struct node *)malloc(sizeof(struct node));
printf("\n Enter the second element = ");
scanf("%d",&data);
temp -> pre = NULL;
temp -> data = data;
temp -> link = NULL;
temp -> pre = head;
head -> link = temp;
temp = (struct node *)malloc(sizeof(struct node));
printf("\n Enter the third element = ");
scanf("%d",&data);
temp -> pre = NULL;
temp -> data = data;
temp -> link = NULL;
head -> link -> link = temp;
temp -> pre = head -> link;
temp -> link = head;
head -> pre = temp;
int ch,value,del;
while(1)
{
printf("\n1.Add at Beginning\n2.Add at End\n3.Add After a Specific value\n4.Add
Before a Specific value\n5.Delete a Specific data\n6.To Delete the after
value\n7.To Delte the Before value\n8.To delte the beginning value\n9.To Delete a
End value\n11.Exit");
printf("\nEnter the choice = ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n Enter the new data = ");
scanf("%d",&data);
head = add_at_beg(head,data);
print(head);
break;
case 2:
printf("\n Enter the new data = ");
scanf("%d",&data);
add_at_end(head,data);
print(head);
break;
case 3:
printf("\n Enter the old data after which you want to add = ");
scanf("%d",&data);
printf("\n Enter the new data = ");
scanf("%d",&value);
add_at_after(head,data,value);
print(head);
break;
case 4:
printf("\n Enter the old data before which you want to add = ");
scanf("%d",&data);
printf("\n Enter the new data = ");
scanf("%d",&value);
add_at_before(head,data,value);
print(head);
break;
case 5:
printf("\n Enter the data which you want to delete = ");
scanf("%d",&data);
del = delete_a_node(head,data);
print(head);
printf("\n The deleted element is = %d",del);
break;
case 6:
printf("\n Enter the data due to which the pre data will be deleted = ");
scanf("%d",&data);
del = del_at_after(head,data);
print(head);
printf("\n The deleted element is = %d",del);
break;
case 7:
printf("\n Enter the data due to which the post data will be deleted = ");
scanf("%d",&data);
del = del_at_before(head,data);
print(head);
printf("\n The deleted element is = %d",del);
break;
case 8:
head = del_at_beg(head);
print(head);
break;
case 9:
del = del_at_end(head);
print(head);
printf("\n The deleted element is = %d",del);
break;
case 11:
exit(1);
break;
}
}
}