#include "sandbox.h"

void *void_to_char_p()
{
	char *test = "Here";
	char **test_p = malloc(sizeof(char *) * 2);

	test_p[0] = test;
	void *ret = (void *)test_p;

	return ret;
}
