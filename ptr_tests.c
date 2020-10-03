# include "sandbox.h"

void *recv_empty(char *str)
{
	printf("adress of recv %p\n", str);
	str = calloc(3, 1);
	str[0] = 'q';

	return (void *)str;
}
