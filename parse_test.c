#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	printf("|%%%%%d%hd%%%*.*d%0- +23.32%d%s%```````````````bbbbbbbbbbbbbbbb|\n", 1, (short)2, 3, 4,  5, "abc");
	ft_printf("|%%%%%d%hd%%%*.*d%0- +23.32%d%s%```````````````bbbbbbbbbbbbbbbb|\n", 1, (short)2, 3, 4,  5, "abc");
}
