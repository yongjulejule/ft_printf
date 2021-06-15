#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
	printf("========================== CHAR TEST ===========================\n");
	unsigned char my_char[4];
	int a = (int)L'오';
	int b = 1234555566;
	unsigned char* d;
	d = (unsigned char*)&b;
	printf("%x\n",d[1]);
	printf("%x\n", b);
	printf("%x\n", (unsigned char)b);
	printf("%x\n", (unsigned char)(b>>8));
	printf("%x\n", (unsigned char)(b>>16));
	printf("%x\n", (unsigned char)(b>>24));
	printf("%d,", (unsigned char)a);
	a >>= 8;
	printf("%d,", (unsigned char)a);
	a >>= 6;
	printf("%d,", a);
	printf("\n\n\n");
	printf("bit cal::%x\n", (unsigned char)(L'오'>>8));
	printf("%x", 152);
//	unsigned char *a = (unsigned char*)"오";
//	printf("\n a =%d", *(a + 1));
	my_char[0] = (unsigned char)236;
	my_char[1] = (unsigned char)152;
	my_char[2] = (unsigned char)164;
	my_char[3] = (unsigned char)48;
	int j = 0;
	while (j < 4)
	{	
		write(1, &my_char[j], 1);
		j++;
	}
//	write(1, "\n", 1);
//	printf("\n|%s|\n", my_char);
//	int i = 0;
//	unsigned char *test = (unsigned char*)"오늘도 밤샐까?";
//	while (test[i])
//	{
//		printf("%d\n", (int)test[i]);
//		i++;
//	}
//	
//	printf("%lc", (wchar_t)(1000));
//	printf("%zu", sizeof(wchar_t*));
//	int t;
//	t = 10L;
//	printf("\ntype size : %zu\n", sizeof(size_t));
}
//11101100 10011000 10100100
