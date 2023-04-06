#include <stdio.h>  
int linearSearch(int a[], int n, int val) {  
  // Going through array sequencially  
  for (int i = 0; i < n; i++)  
    {  
        if (a[i] == val)  
        return i+1;  
    }  
  return -1;  
}  
int main() {  

  int a[10],n,c,val;

  printf("\nName : Prachi Chhatrola\n");  
  printf("Enrollment No. : 210210116030\n");
  printf("How Many Element You Want To Add:");
  scanf("%d", & n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++){
    scanf("%d", & a[c]);}

    printf("Enter value to be searched : ");
    scanf("%d",&val);

  int res = linearSearch(a, n, val); // Store result  
  printf("The elements of the array are : ");  
  for (int i = 0; i < n; i++)  
  printf("%d ", a[i]);   
  printf("\nElement to be searched is  %d", val);  
  if (res == -1)  
  printf("\nElement is not present in the array");  
  else  
  printf("\nElement is present at %d position of array", res);  
  return 0;  
}  