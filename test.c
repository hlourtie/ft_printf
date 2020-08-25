#include <stdio.h>
#include <stdlib.h>
#include "./inc/ft_printf.h"
#include <limits.h>

int main()
{ 	
    ft_printf("%0166.*d\n" ,-27,-322024980);
    printf("%0166.*d\n" ,-27,-322024980);
	



	//system("leaks a.out");
	return 0;
}
