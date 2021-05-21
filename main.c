#include <stdio.h>
#include "ft_printf.h"

void testfunction(t_lidx *test)
{
	test->opts.length = 3;
}

int main()
{
	t_lidx test;

	ft_printf("really%2$-+0 *.123dbcsdsdlkj%123$  000123.432fasdbfd%c");
	printf("%c",(char)-200);

	testfunction(&test);
	printf("%d\n", test.opts.length);
	printf("|%----------100.5ss|\n", "THis is str");
	printf("|%100ss|\n", "THis is str");
	printf("|%++++++00++++100ds|\n", 100);
	printf("|%++--++++++++100ds|\n", 100);
	printf("|%     00100ds|\n", 100);
	printf("|%++++++00++++100ds|\n", 100);
	printf("|%*s|\n",100, "isthis");

	printf("u opt is |%100uds|\n", -1);
	printf("|%100ds|\n", 100);
	printf("|%100ds|\n", 100);
}
