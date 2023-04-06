#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
struct item
{
    int key;
    int value;
};
struct hashtable_item
{

    int flag;

    struct item *data;

};

struct hashtable_item *array;
int size = 0;
int max = 10;
void init_array()
{
    int i;
    for (i = 0; i < max; i++)
    {
	array[i].flag = 0;
	array[i].data = NULL;
    }
}
int middleDigit(int n)
{
int digits = log10(n) + 1;
n = fmod((n / pow(10, digits / 2)), 10);
return n;
}

int sumDigit(int n){
        int sum=0,m;
while(n>0)
    {
    m=n%10;
    sum=sum+m;
    n=n/10;}
    return sum%max;
}

int hashcode(int select,int key)
{
    switch(select){
        case 1:
            return (key % max);  /* Division Method*/
            break;
        case 2:{
            float a=0.357;
            int ans;
            ans=floor((max*fmod((key*a),1)));
            return ans; // multiplication method*/
            }
            break;
        case 3:
            return middleDigit(key*key);//middle square Method
            break;
        case 4:
                return sumDigit(key);//Folding Method
            break;
    }

}

void insert( int se,int value)
{
    int index,key;
     index=key = hashcode(se,value);
    int i = index;
    struct item *new_item = (struct item*) malloc(sizeof(struct item));
    new_item->key = key;
    new_item->value = value;
    while (array[i].flag == 1)
    {
	if (array[i].data->key == key)
        {
		printf("\nKey already exists, hence updating its value \n");
        i = (i + 1) % max;
      if (i == index)
        {
		printf("\nHash table is full, cannot insert any more item \n");
		return;
		exit(1);
	}
	}
    }
    array[i].flag = 1;
    array[i].data = new_item;
    size++;
    printf("\nKey (%d) has been inserted \n", key);

}

void display()
{
    int i;
    for (i = 0; i < max; i++)
    {
	struct item *current = (struct item*) array[i].data;

	if (current == NULL)
        {
	    printf("\nArray[%d] has no elements \n", i);
	}
	else
        {
	    printf("\nArray[%d] has elements : \n  %d (key) and %d(value) ", i, current->key, current->value);
	}
    }

}

int size_of_hashtable()
{
    return size;
}

void main()
{
	int choice, key, value, n, c,se;

	printf("\nName : Prachi Chhatrola \n");
  	printf("Enrollment No. : 210210116030 \n");

    array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item));
	init_array();

	do {
		printf("\nImplementation of Hash Table in C with Linear Probing \n\n");
		printf("MENU-: \n1.Inserting item in the Hashtable"
                              "\n2.Check the size of Hashtable"
                              "\n3.Display Hashtable"
                              "\n4.Exit"
		       "\n\n Please enter your choice : ");

		scanf("%d", &choice);

		switch(choice)
        {
		case 1:
            f:
		      printf("\nInserting element in Hashtable...\n");
		      printf("Enter value : ");
		      scanf("%d", &value);
		      printf("\nSelect Which Technique you will  insert a value\n"
               "1.Division\n" "2.Multiplication\n" "3.Mid square\n""4.Folding\n");
               scanf("%d",&se);
               if(se>4){printf("Wrong Choice\n"); goto f;}
               else{insert(se,value);}
		      break;
		case 2:
		      n = size_of_hashtable();
		      printf("Size of Hashtable is : %d\n", n);
		      break;
		case 3:
		      display();
		      break;
		case 5: exit(0);
		      break;
		default:
		      printf("Wrong Input\n");
		}
	}while(choice != 4);
}
