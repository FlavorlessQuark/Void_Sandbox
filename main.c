#include "sandbox.h"


int main()
{
	printf("Cast to void and back : %s\n", *(char **)void_to_char_p()); //This works just fine
}
