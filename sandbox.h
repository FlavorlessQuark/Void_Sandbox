#ifndef SANDBOX_H
# define SANDBOX_H

#include <stdio.h>
#include <stdlib.h>

void overload_i(int a);
void overload_sh(short a);
void overload_l(long a);
void overload_s(char *a);
void overload_c(char a);
void overload_mulint(int a)

// void overload_s(char *a);

# define overload_simple(_1) _Generic((_1), int : overload_i, short : overload_sh, long : overload_l)(_1)
# define overload_string(_1) _Generic((0,_1), char * : overload_s, int : overload_c)(_1)

// # define overload_multiple(_1,...)
// The above also has some problems with chars... Chars are integer types so there might lie the problem
// Using int instead of char seems to silve the problem... for now.

// Having to "cast" the argument as a pointer makes it tricky if you want to select a function
// based whether it is an int or str. It might be solved with another _Generic inside a call to default


typedef struct _keyval
{
	char *str;
	int val;
}				_Pair

void *void_to_char_p();
void *recv_empty(char *str);
void *deref();

#endif
