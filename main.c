#include <stdio.h>
#include "ft_printf.h"

int main()
{

	ft_printf("really%-+0 *.123dbcsd%KKKKKKKKKKKKKKKsdlkj%  000123.432fasdbfd%c\n", 10, "hello", 10.0, 'c');
	printf("==============decimal check==================\n");
	printf("%01d\n", -10);
	printf("%- .100d\n", 10);
	printf("%-d\n", 10);
	printf("%+d\n", 10);
	printf("% d\n", 10);
	printf("==============float check==================\n");
	printf("%g\n", 10.1234);
	printf("return is %d\n",	printf("%- .500g\n", 10.424242));
	printf("%-e\n", 4242.42424242424242424242424242424);

	printf("==============string check=====================");
	printf("\n\n%c\n\n",(char)-200);
	printf("|%030ss|\n", "THis is str");
	
	printf("ERROR_CASE(FLAG)|%+100ss|\n", "THis is str");
	printf("ERROR_CASE(NOT SPECIFIER)|%++++++00++++100Kds|\n", 100);
	printf("|%++--++++++++100ds|\n", 100);
	printf("|%     00100ds|\n", 100);
	printf("|%++++++00++++100ds|\n", 100);
	printf("|%*s|\n",100, "isthis");

	printf("u opt is |%100uds|\n", -1);
	printf("|%100ds|\n", 100);
	printf("|%100ds|\n", 100);
}
