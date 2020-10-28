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

	printf("-----------------Generic tests here-----------------\n");
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
	printf("-----------------Voids tests here-----------------\n");
	// printf("test1 %c\n", *(char *)&hold[0]); // Actually have to take the adress and then cast it and then dereference it...
	printf("test4 %s\n", (char *)hold + 1); //This returns the expected "ello"
	printf("test4 %s\n", (char *)hold + 1); //This returns the expected "ello"

}

void ptrs()
{
	char *empty;
	void *recv;

	recv = recv_empty(empty);

	printf("-----------------Ptrs tests here------------------\n");
	printf("Cast to void and back : %s\n\n", *(char **)void_to_char_p());
	printf("Original: %p , %s\t REcv %p , %s\n", recv, (char *)recv, empty, (char *)empty);// Original string adress doesn't change. The allocated adress differs
}

void casstest()
{
	char *abc = {"abc"};
	void *ptr;
	char *tmp = {"cedf"};
	int b[] = {0,1};

	int a;
	ptr = tmp;
	printf("%s %d\n",  (typeof(abc))(ptr), (typeof(a))(b[0]));
}

void structtest()
{
	s_types typetest;

	int a;
	char b;
	char *str;
	double d;
	void **test;

	typetest.character = 'a';
	printf("Char   : (%ld) %p	\n",sizeof(typetest.character),	(&(typetest.character)));
	printf("Int    : (%ld) %p	\n",sizeof(typetest.intger),		(&(typetest.intger)));
	printf("Str    : (%ld) %p	\n",sizeof(typetest.str),			(&(typetest.str)));
	printf("Float  : (%ld) %p	\n",sizeof(typetest.decimal),		(&(typetest.decimal)));
	printf("Double : (%ld) %p	\n",sizeof(typetest.decdouble),	(&(typetest.decdouble)));
	*test = &a;
	long save = sizeof(*(&(typetest.character)));
	printf("Save : %ld\n", sizeof(test));
	if (__builtin_types_compatible_p(typeof(test), typeof(a)))
		printf("SAME\n");
	else
		printf("NOT\n");
}

int main()
{
	// generics();
	// voids();
	// ptrs();
	// structtest();
	casstest();
}
