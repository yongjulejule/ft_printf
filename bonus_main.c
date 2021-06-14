#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
	printf("========================== CHAR TEST ===========================\n");
	unsigned char my_char[4];
	int a = (int)L'집';
	printf("%d,", (unsigned char)a);
	a >>= 7;
	printf("%d,", (unsigned char)a);
	a >>= 8;
	printf("%d,", a);
	printf("\n\n\n");
	my_char[0] = (unsigned char)236;
	my_char[1] = (unsigned char)167;
	my_char[2] = (unsigned char)145;
	my_char[3] = (unsigned char)0;
	int j = 0;
	while (j < 3)
	{	
		write(1, &my_char[j], 1);
		j++;
	}
	write(1, "\n", 1);
	printf("\n|%s|\n", my_char);
	int i = 0;
	unsigned char *test = (unsigned char*)"오늘도 밤샐까?";
	while (test[i])
	{
		printf("%d\n", (int)test[i]);
		i++;
	}
	
	printf("%lc", (wchar_t)(1000));
	printf("%zu", sizeof(wchar_t*));
	int t;
	t = 10L;
	printf("\ntype size : %zu\n", sizeof(size_t));
	printf("======================= INT TEST ===========================\n");
	printf("oringin: %d, cast_char: %hhd, cast_short: %hd, cast_long %ld , cast_long long %lld", t, (char)t, (short)t, (long)t, (long long)t);
}
