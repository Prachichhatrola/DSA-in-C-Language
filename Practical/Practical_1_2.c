#include <stdio.h>
#include <string.h>

int main()
{
	char str[50][50], temp[50];
	int i, j, number;
    printf("Name: Prachi Chhatrola\n");
	printf("Enrollment No.: 210210116030\n");
	printf("How many Strings you want to enter = ");
	scanf("%d", &number);

	printf("Please Enter String one by one\n");
	for (i = 0; i <= number; i++)
	{
		fgets(str[i], sizeof str[i], stdin);
	}
	for (i = 0; i <= number; i++)
	{
		for (j = i + 1; j <= number; j++)
		{
			if (strcmp(str[i], str[j]) > 0)
			{
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp);
			}
		}
	}

	printf("\n***** The Order of the  Sorted Strings *****");
	for (i = 0; i <= number; i++)
	{
		puts(str[i]);
	}
	return 0;
}