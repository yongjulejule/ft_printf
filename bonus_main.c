#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	unsigned char *test = (unsigned char*)"집에가야지";
	unsigned char my_char[4];
	my_char[0] = (unsigned char)236;
	my_char[1] = (unsigned char)167;
	my_char[2] = (unsigned char)145;
	my_char[3] = 0;
	int j = 0;
	while (j < 3)
	{	
		write(1, &my_char[j], 1);
		j++;
	}
//	printf("\n|%s|\n", my_char);
//	int i = 0;
//	while (test[i])
//	{
//		printf("%d\n", (int)test[i]);
//		i++;
//	}
//	
	printf("========================== CHAR TEST ===========================\n");
}
