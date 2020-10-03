# include <stdio.h>
# include "sandbox.h"

void overload_i(int a){printf("int %d\n", a);}
void overload_sh(short a){printf("short %d\n", a);}
void overload_l(long a){printf("long %ld\n", a);}
void overload_s(char *a){printf("str %s\n", a);}
void overload_c(char a){printf("str %c\n", a);}

int generics()
{
	short b = 2;

	print("-----------------Generic tests here-----------------\n");
	overload_simple(1L);
	overload_simple(b);
	overload_simple(1);

	overload_string("Hello");
	overload_string('a');
	return 0;
}



void *voids()
{
	char *str = "Hello";
	void *hold;

	hold = (void *)str;

	// printf("test2 %c\n", (char)&hold[0]); //This returns 'D' instead of H, wrong memory adress...
	// printf("test3 %s\n", (char *)&hold + 1); //This returns 'D' instead of H, wrong memory adress...
	// printf("test4 %c\n", *(char *)hold + 1); //This returns 'I' instead of H, wrong memory adress...
	print("-----------------Voids tests here-----------------\n");
	printf("test1 %c\n", *(char *)&hold[0]); // Actually have to take the adress and then cast it and then dereference it...
	printf("test4 %s\n", (char *)hold + 1); //This returns the expected "ello"
	printf("test4 %s\n", (char *)hold + 1); //This returns the expected "ello"

	printf("\nDereferncing void * ");
	deref();
}

void ptrs()
{
	char *empty;
	void *recv;

	recv = recv_empty(empty);

	print("-----------------Ptrs tests here------------------\n");
	printf("Cast to void and back : %s\n\n", *(char **)void_to_char_p());
	printf("Original: %p , %s\t REcv %p , %s\n", recv, (char *)recv, empty, (char *)empty);// Original string adress doesn't change. The allocated adress differs
}

int main()
{
	generics();
	voids();
	ptrs();
}
